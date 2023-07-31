#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <receiver IP> <receiver port>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct sockaddr_in receiver_addr;
    char sendline[MAXLINE], recvline[MAXLINE];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set receiver address
    memset(&receiver_addr, 0, sizeof(receiver_addr));
    receiver_addr.sin_family = AF_INET;
    receiver_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &receiver_addr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(1);
    }

    // Continuously exchange messages with the receiver
    while (fgets(sendline, MAXLINE, stdin) != NULL) {
        // Send message to receiver
        if (sendto(sockfd, sendline, strlen(sendline), 0,
                   (struct sockaddr *)&receiver_addr, sizeof(receiver_addr)) == -1) {
            perror("sendto error");
            exit(1);
        }

        // Receive message from receiver
        int n = recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);
        if (n == -1) {
            perror("recvfrom error");
            exit(1);
        }
        recvline[n] = '\0';

        // Print received message
        fputs(recvline, stdout);

        // Check for exit message
        if (strcmp(recvline, "exit\n") == 0) {
            break;
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}
