#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){

	char server_message[256] = "Your message has been delivered to the server";

	//create the server socket
	int server_socket;
	server_socket = socket(AF_INET,SOCK_STREAM,0);

	//define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");


	//bind the socket to our specified IP and port
	bind(server_socket,(struct sockaddr *)&server_address,sizeof(server_address));

	listen(server_socket,5);

	int client_socket;
	client_socket = accept(server_socket,NULL,NULL);
	printf("Client Connected\n");


	char message[256];
	//recivng the message
	printf("Receiving the message from the client\n\n");
	recv(client_socket,message,sizeof(message)-1,0);
	printf("Message recieved from the client is %s\n",message);

	printf("Now send the message to the client\n");
	//send the message
	send(client_socket,server_message,sizeof(server_message),0);

	//close the socket
	close(server_socket);

	return 0;

}
