#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <sender IP> <sender port>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct sockaddr_in sender_addr;
    char sendline[MAXLINE], recvline[MAXLINE];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set sender address
    memset(&sender_addr, 0, sizeof(sender_addr));
    sender_addr.sin_family = AF_INET;
    sender_addr.sin_port = htons(atoi(argv[2]));
    sender_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind the socket to the sender address
    if (bind(sockfd, (struct sockaddr *)&sender_addr, sizeof(sender_addr)) == -1) {
        perror("bind error");
        exit(1);
    }

    // Continuously exchange messages with the sender
    while (1) {
        // Receive message from sender
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

        // Send message to sender
        if (fgets(sendline, MAXLINE, stdin) == NULL) {
            break;
        }
        if (sendto(sockfd, sendline, strlen(sendline), 0,
                   (struct sockaddr *)&sender_addr, sizeof(sender_addr)) == -1) {
            perror("sendto error");
            exit(1);
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}
