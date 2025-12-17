// server.c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    char buffer[1024];

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Define server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);          // Port number
    server_addr.sin_addr.s_addr = INADDR_ANY;    // Accept from any IP

    // Bind socket to IP + port
    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // Listen for incoming connections
    listen(server_fd, 5);
    printf("Server listening on port 8080...\n");

    // Accept client connection
    client_fd = accept(server_fd, NULL, NULL);
    printf("Client connected!\n");

    // Receive message from client
    recv(client_fd, buffer, sizeof(buffer), 0);
    printf("Message from client: %s\n", buffer);

    // Close sockets
    close(client_fd);
    close(server_fd);

    return 0;
}

