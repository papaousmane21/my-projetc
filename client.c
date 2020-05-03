#include <arpa/inet.h>
#include <netdb.h>  
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <sys/uio.h>
#include <sys/socket.h>
#include <unistd.h> 
#include <stdio.h> 
#include <pthread.h> 
#include <sys/select.h> 
#include <sys/time.h>
#include <sys/types.h>
#include <netinet/in.h>

typedef struct User
{
	char nom[30];
	int age;
}User;
int main(void){

int socketClient = socket(AF_INET, SOCK_STREAM, 0); 
    struct sockaddr_in addrClient;
    addrClient.sin_family = AF_INET; 
    addrClient.sin_addr.s_addr = inet_addr("127.0.0.1") ; 
    addrClient.sin_port = htons(30000);
    connect(socketClient, (const struct sockaddr *)&addrClient, sizeof(addrClient));
    printf("connecté \n");

    User user;
    char msg[33];
    recv(socketClient, msg, 32,0);
    printf("%s\n",msg);
    scanf("%s %d",user.nom,&user.age);
    send(socketClient, &user, sizeof(user),0);
    close(socketClient);
return 0;

}
