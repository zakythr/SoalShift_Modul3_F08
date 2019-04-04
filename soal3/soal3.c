#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

pthread_t tid1, tid2;
int manggil_agmal;
int manggil_iraj;
int status_agmal=0;
int status_iraj=100;
int hitung_agmal=0;
int hitung_iraj=0;
int tanda=0;

void *cekagmal(void *arg)
{
	while(1)
	{
		if(manggil_agmal==0)
		{
			sleep(10);
			manggil_agmal=1;
			hitung_agmal=0;
		}
	}
}

void *cekiraj(void *arg)
{
	while(1)
	{
		if(manggil_iraj==0)
		{
			sleep(10);
			manggil_iraj=1;
			hitung_iraj=0;
		}
	}
}

void *agmal_bangun(void *arg)
{
	status_agmal+=15;
	if(status_agmal>=100)
	{
		printf("Agmal Terbangun,mereka bangun pagi dan berolahraga\n");
		tanda=1;
	}
}

void *iraj_bangun(void *arg)
{
	status_iraj-=20;
	if(status_iraj<=0)
	{
		printf("Iraj ikut tidur, dan bangun kesiangan bersama Agmal\n");
		tanda=1;
	}
}


int main(void)
{
	char pesan[50];
	int fitur_agmal;
	int fitur_iraj;
	int fitur_allstatus;
	char temp;
	manggil_agmal=1;
	manggil_iraj=1;
	pthread_t tid[4];
	
	while(1)
	{
		if(tanda==1)break;
		scanf("%[^\n]s", pesan);
		scanf("%c", &temp);
		fitur_agmal=strcmp(pesan, "Agmal Ayo Bangun");
		fitur_iraj=strcmp(pesan, "Iraj Ayo Tidur");
		fitur_allstatus=strcmp(pesan, "All Status");
		

	if(fitur_agmal==0)
	{
		if(manggil_agmal=1)
		{
			pthread_create(&(tid[0]), NULL, agmal_bangun, NULL);
			hitung_agmal++;
			pthread_join( tid[0], NULL);
		}
		if(hitung_agmal%3==0 && hitung_agmal!=0)
		{
			manggil_iraj=0;
			pthread_create(&(tid[3]), NULL, cekiraj, NULL);
			printf("Fitur Iraj Ayo Tidur disabled 10 s\n");
			hitung_agmal=0;
		}
	}

	if(fitur_iraj==0)
	{
		if(manggil_iraj==1)
		{
			pthread_create(&(tid[1]), NULL, iraj_bangun, NULL);
			hitung_iraj++;
			pthread_join( tid[1], NULL);
		}
		if(hitung_iraj%3==0 && hitung_iraj!=0)
		{
			manggil_agmal=0;
			pthread_create(&(tid[2]), NULL, cekagmal, NULL);
			printf("Agmal Ayo Bangun disabled 10 s\n");
			hitung_iraj=0;
		}
	}
	
	if(fitur_allstatus==0)
	{
		printf("Agmal WakeUp_Status = %d\n", status_agmal);
		printf("Iraj Spirit_Status = %d\n", status_iraj);
		printf("%d\n", hitung_iraj);
		printf("%d\n", hitung_agmal);
	}
	pesan[0] = '\0';
   }
return 0;
}
