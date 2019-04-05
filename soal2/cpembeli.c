#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8081


  
int main(int argc, char const *argv[]) 
{
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char tambah[50];
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    {
        printf("\n Socket creation error \n");
        return -1;
    }
  
    memset(&serv_addr, '0', sizeof(serv_addr));
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
      
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    printf("Koneksi dengan server telah berhasil\n");

    printf("Ketik 'beli' untuk mengurangi stok : ");
    scanf("%s \n", beli);
    while(1){
        
        if(strcmp(beli, "beli")==0)
        {
            send(sock, beli, strlen(beli), 0);
            valread = read(sock, buffer, 1024);
            printf("%s \n", buffer);
        }
        else{
            printf("Mohon maaf, request Anda salah");
        }
        sleep(1);
    }
    return 0;
}