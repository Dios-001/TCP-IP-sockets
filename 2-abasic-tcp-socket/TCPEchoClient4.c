/*
    create TCP socket 
    establish connection 
    communicate 
    close the connection 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include "Practical.h"

int main(int argc, char *argv[]){
    if(argc < 3 || argc > 4){
        DieWithUserMessage("Parameter(s)", "<Server Address> <Echo Word> [<Server Port>]");
    }

    char *servIP = argv[1]; //server address in IPv4 (dotted quad notation)
    char *echoString = argv[2]; // string to be echoed 

    //Third arg (optional): server port<numeric>. 7 is common echo port
    in_port_t servPort = (argc == 4) ? atoi(argv[3]) : 7;

    //create a reliable, stream socket using tcp 
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock < 0)
    {  DieWithSystemMessage("socket() failed");}
    
    //construct tehr server address structure
    struct sockaddr_in servAddr; //server address
    memset(&servAddr, 0 , sizeof(servAddr)); //zero out structure
    servAddr.sin_family = AF_INET; //IPv4 address family
    
    //convert address 
    int rtnVal = inet_pton(AF_INET, servIP, &servAddr.sin_addr.s_addr)
    if(rtnVal == 0 ){
        DieWithUserMessage("inet_pton() failed", "invalid address string");
    }else if(rtnVal < 0 ){
        DieWithSystemMessage("inet_pton() failed");
    }

    servAddr.sin_port = htons(servPort); // Server port 

    //Establish the connection to the echo server 
}