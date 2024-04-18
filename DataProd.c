#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "pipe_functions.h"  // Assume this header file declares writeToPipe and readFromPipe

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <pipe_path> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *pipe_path = argv[1];
    const char *message = argv[2];

    // Example: Open the pipe - in real use, you might need to create it or open it differently
    int pipe_fd = open(pipe_path, O_WRONLY);
    if (pipe_fd == -1) {
        perror("Failed to open pipe");
        return EXIT_FAILURE;
    }

    // Write to pipe
    if (!writeToPipe(pipe_fd, message)) {
        fprintf(stderr, "Failed to write to pipe\n");
        close(pipe_fd);
        return EXIT_FAILURE;
    }

    close(pipe_fd);
    return EXIT_SUCCESS;
}