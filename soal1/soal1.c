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
	struct Faktorial*extract=(struct Faktorial*)args;
	for(int a=1; a<=extract->nilai; ++a)
	{
		faktor=a*faktor;
	}
	printf("%d! = %llu \n", extract->nilai, faktor);
	printf("\n");
}

int array[10000];

int main()
{
	int a=0, b=0, urut, x;
	char temp;
	do
	{
		scanf("%d%c", &array[a], &temp);
		a++;
	}while(temp != '\n');

	for(a = 0; array[a]!='\0'; ++a)
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
	while(array[a]!='\0')
	{
		dipanggil.nilai=array[a];
		urut=array[a];
		pthread_create(&tid[urut], NULL, &proses, (void *)&dipanggil);
		pthread_join(tid[urut], NULL);
		a++;
	}
	return 0;
}
