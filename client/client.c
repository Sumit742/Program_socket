// client.c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock_fd;
    char message[] = "Hello from client!";

    // Create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Define server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // localhost

    //Connect to server
    connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // Send message to server
    send(sock_fd, message, strlen(message), 0);

    // wClose socket
    close(sock_fd);

    return 0;
}

