#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){

	//create a socket
	int network_socket;
	network_socket = socket(AF_INET,SOCK_STREAM,0);

	//Specify an address for the socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");


	int connection_status = connect(network_socket,(struct sockaddr *)&server_address,sizeof(server_address));

	//Check for error with the connection
	if(connection_status == -1){
	printf("There is error making a connectoin to the remote server \n\n");
	
	}
	char message[250] = "Hellow my name is Sumit";
	printf("Before receiving I'm sending the data\n");
	send(network_socket,message,sizeof(message),0);

	//receive data from the server
	char server_response[256];
	recv(network_socket,&server_response,sizeof(server_response),0);

	//print out the server response
	printf("Data Sent by the server is: %s\n", server_response);

	//close the socket
	close(network_socket);
	return 0;

}
