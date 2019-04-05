#include<unistd.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<pthread.h>

pthread_t tid[50];

struct Faktorial
{
	int nilai;
};

void *proses(void *args)
{
	unsigned long long faktor=1;
	struct Faktorial*extract=(struct Faktorial*)args;	//mengubah nilai array menjadi variabel dan nilainya 
	for(int a=1; a<=extract->nilai; ++a)
	{
		faktor=a*faktor;	//pengkalian faktorial
	}
	printf("%d! = %llu \n", extract->nilai, faktor);
}

int array[10000];

int main(int argc, char *argv[])
{
	int a=0;
	int b=0;
	int urut;
	int x;
	char space;


 	for(int i=1;i<argc;i++){
             array[i-1]=atoi(argv[i]);
        }

	for(a = 0; array[a]!='\0'; ++a)			//untuk mengurutkan angka yang akan difaktorialkan
	{
		for(b = a + 1; array[b]!='\0'; ++b)
		{
			if(array[a] > array[b])
			{
				x=array[a];
				array[a]=array[b];
				array[b]=x;
			}
		}
	}
	
	a=0;
	struct Faktorial dipanggil;
	while(array[a]!='\0')			//untuk mengfaktorialkan
	{
		dipanggil.nilai=array[a];
		urut=array[a];
		pthread_create(&tid[urut], NULL, &proses, (void *)&dipanggil);
		pthread_join(tid[urut], NULL);
		a++;
	}
	return 0;
}
