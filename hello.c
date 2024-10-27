#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <assert.h>
#include <signal.h>

volatile sig_atomic_t stop = 0;

// Function to return the "Hello World" message
const char* getHelloMessage() {
    return "Hello World";
}

// Function to test that the output is "Hello World"
const char* testHelloMessage() {
    assert(strcmp(getHelloMessage(), "Hello World") == 0);
    return "Test passed: getHelloMessage() returns 'Hello World'";
}

// Function to handle incoming client requests
void handle_client(int client_socket) {
    char buffer[1024];
    int bytes_read = read(client_socket, buffer, sizeof(buffer) - 1);
    if (bytes_read > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the buffer

        // Print the request for debugging
        printf("Received request:\n%s\n", buffer);

        // Prepare the response
        const char* response_body = testHelloMessage();
        char response[2048];
        snprintf(response, sizeof(response),
                 "HTTP/1.1 200 OK\r\n"
                 "Content-Type: text/plain\r\n"
                 "Content-Length: %ld\r\n"
                 "Connection: close\r\n"
                 "\r\n"
                 "%s",
                 strlen(response_body), response_body);

        // Send the response to the client
        write(client_socket, response, strlen(response));
    }
    close(client_socket);
}

// Signal handler to gracefully stop the server
void handle_signal(int signal) {
    if (signal == SIGINT || signal == SIGTERM) {
        stop = 1; // Set the stop flag
    }
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Set up signal handling
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    server_addr.sin_port = htons(8080); // Port 8080

    // Bind the socket
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 10) < 0) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 8080...\n");

    while (!stop) {  // Run until a stop signal is received
        // Accept a new connection
        client_socket = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            if (stop) break; // Break if we received a stop signal
            perror("accept");
            continue;
        }

        // Handle the client in a separate function
        handle_client(client_socket);
    }

    // Close the server socket
    close(server_fd);
    printf("Server stopped.\n");
    return 0;
}
