#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<math.h>

pthread_t tid[50];


struct Urut{
	int proses;
	int min;
	int max;
};

void* menulis(void* args){
    char arr[200];
    struct Urut*extract =(struct Urut*)args;
    
    //buat folder FolderProses
    sprintf(arr,"mkdir /home/zaky/Documents/FolderProses%d",extract->proses);
    system(arr);

    //untuk pengambilan isi aux dan disimpan di SimpanProses*.txt yg berada di folder FolderProses
    strcpy(arr,"");
    sprintf(arr,"ps aux --no-heading | head -%d  | tail -%d > /home/zaky/Documents/FolderProses%d/SimpanProses%d.txt",extract->max,extract->min,extract->proses,extract->proses);
    system(arr);

    //lalu dizip dengan nama "KompresProses*.zip"
    strcpy(arr,"");
    sprintf(arr,"zip -qmj /home/zaky/Documents/FolderProses%d/KompresProses%d /home/zaky/Documents/FolderProses%d/SimpanProses%d.txt",extract->proses,extract->proses,extract->proses,extract->proses);
    //print arr
    system(arr);	
}

void* mengunzip(void* args){
    char arr[200];
    struct Urut*extract =(struct Urut*)args;
    strcpy(arr,"");
    sprintf(arr,"unzip -qd /home/zaky/Documents/FolderProses%d /home/zaky/Documents/FolderProses%d/KompresProses%d.zip",extract->proses,extract->proses,extract->proses);
    system(arr);
}  


int main(){
  int n=2;
  struct Urut urut;
  urut.proses=0;
  urut.min=10;
  urut.max=10;
  
  for(int x=1; x<=n; x++){
	urut.proses=x;
	pthread_create(&tid[x], NULL, &menulis,(void *)&urut);
        pthread_join(tid[x],NULL);
	urut.max=urut.max+10;
  }

  printf("Menunggu 15 detik\n");
  for(int a=1; a<=15;a++){
	printf("%d\n",a);
	sleep(1);
  }

  for(int b=1; b<=n; b++){
	urut.proses=b;
	pthread_create(&tid[b], NULL, &mengunzip,(void *)&urut);
        pthread_join(tid[b],NULL);
  }
    
    return 0;
}
