#include <termios.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int stokmakanan=150;
int cooldown=20;
int sken=0;
int statushunger=250;
int statussehat=300; 
int statushygien=150;
char buang;
char milih;


int prosesutama(void)
{
    struct termios oldt, newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}

void menampilkan(){
    while(1){
        if (sken == 0) {
            printf("Standby Mode\n");
            printf("Health: %d \n", statussehat);
            printf("Hunger: %d \n", statushunger);
            printf("Hygiene: %d \n", statushygien);
            printf("Health: %d \n", statussehat);
            printf("Food left : %d\n", stokmakanan);
            printf("Bath will be ready in %ds \n", cooldown);
            printf("Choiches\n");
            printf("1. Eat\n");
            printf("2. Bath\n");
            printf("3. Battle\n");
            printf("4. Shop\n");
            printf("5. Exit\n");
            sken = prosesutama();
        }

        if (sken == 1){
            printf("Battle Mode\n");
            printf("Monster's Health: %d \n", statussehat);
            printf("Monster's Health %d \n", statushunger);
            printf("Choiches\n");
            printf("1. Attack\n");
            printf("2. Run\n");
        }

        if (sken == 2){
            printf("Shop Mode\n");
            printf("Shop Food Stock: %d \n", statussehat);
            printf("Your Food Stock: %d \n", statushunger);
            printf("Choiches\n");
            printf("1. Buy\n");
            printf("2. Back\n");
        }
        
        sleep(1);
    }
    
}

void pengurangan(){
    while(1){
        if(1){
            statushunger = statushunger - 5;
            printf("Hunger_Status = %d\n", statushunger);
            sleep(1);
        }
    }
}

void aktifitas(char pilihmenu){
    if(pilihmenu == '1'){
        printf("menu %c\n", pilihmenu);
    }

    if(pilihmenu == '2'){
        printf("menu %c\n", pilihmenu);
    }

    if(pilihmenu == '3'){
        printf("menu %c\n", pilihmenu);
    }

    if(pilihmenu == '4'){
        printf("menu %c\n", pilihmenu);
    }

    if(pilihmenu == '5'){
        printf("menu %c\n", pilihmenu);
    }
}

char monsterku[50];

int main(){
    printf("Masukkan nama monster kamu: ");
    scanf("%s", monsterku);
    printf("%s\n", monsterku);
    menampilkan();
    scanf("%c",&buang);
    aktifitas(sken);
    pengurangan();
}
