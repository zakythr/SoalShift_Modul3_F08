#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int bangun=0;
int ayo_semangat=100;
char pesan[50];
int tanda=0;
int tandai=0;
int hitungsleep=0;
int hitungbangun=0;
pthread_t tid;

void* status_agmal(void* args){
	while(1){
	  if(hitungsleep==3){
		sleep(10);
		tanda=0;
		hitungsleep=0;
		printf("Wes Tangi\n");
	  }
	  else{
		if(tanda==1){
			hitungbangun++;
			bangun+=15;

			if(hitungbangun>3){
				hitungbangun=1;
			}

			if(hitungbangun==3){
				printf("Fitur Iraj Tidur disabled 10 s\n");
			}
			tanda=0;
		}
	  }	
	}
}

void* status_iraj(void* args){
	while(1){
	  if(hitungbangun==3){
		sleep(10);
		tandai=0;
		hitungbangun=0;
		printf("Wes Turu Le\n");
	  }
	  else{
		if(tandai==1){
			hitungsleep++;
			ayo_semangat-=20;

			if(hitungsleep>3){	
				hitungsleep=1;
			}
			if(hitungsleep==3){
				printf("Agmal Ayo Bangun disabled 10 s\n");
			}
			tandai=0;
		}
	  }	
	}
}

int main(){
	int fitur_agmal;
	int fitur_iraj;
	int fitur_allstatus;

	pthread_create(&tid, NULL, &status_agmal,NULL);
	pthread_create(&tid, NULL, &status_iraj,NULL);

	while(bangun<100 && ayo_semangat>0 && bangun!=100 && ayo_semangat!=0){
		memset(pesan,0,30);
		gets(pesan);
		
		fitur_agmal=strcmp(pesan, "Agmal Ayo Bangun");
		fitur_iraj=strcmp(pesan, "Iraj Ayo Tidur");
		fitur_allstatus=strcmp(pesan, "All Status");
		
		if(fitur_allstatus==0){
			printf("Agmal->WakeUp_Status = %d\n", bangun);
			printf("Iraj->Spirit_Status = %d\n", ayo_semangat);
		}else
		if(fitur_agmal==0){
			tanda=1;
		}else
		if(fitur_iraj==0){
			tandai=1;
		}

		if(bangun>=100){
        	printf("Agmal Terbangun,mereka bangun pagi dan berolahraga\n");
			return 0;
    	}else
		if(ayo_semangat<=0){
        	printf("Iraj ikut tidur, dan bangun kesiangan bersama Agmal\n");
			return 0;
   		}
	}  
}
