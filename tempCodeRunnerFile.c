#include <stdio.h>      
#include <winsock2.h>                   
#include <stdlib.h>     
#include <string.h>     
#include <unistd.h>     
#define ECHOMAX 255     

int main(int argc,char *argv[])
{
    int sock;
    struct sockaddr_in echoServAddr;
    struct sockaddr_in fromAddr;
    unsigned short echoServerPort=7;
    unsigned int fromSize;
    char *servIP="172.24.23.4";
    char *echoString="I hope this works";
    char *echoBuffer[ECHOMAX+1];
    int echoStringLen;
    int respStringLen;
    
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    memset(&echoServAddr, 0, sizeof(echoServAddr));  
    echoServAddr.sin_family = AF_INET;  
    echoServAddr.sin_addr.s_addr = htonl(servIP);  
    echoServAddr.sin_port = htons(echoServPort); 
    sendto(sock, echoString, echoStringLen, 0, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr);

    fromSize = sizeof(fromAddr);
    recvfrom(sock,echoBuffer,ECHOMAX,0,(struct sockaddr*)&fromAddr,&fromSize);

    echoBuffer[echoStringLen]='\0';
    printf("Received:%s\n",echoBuffer);
    close(sock);
    exit(0);

}