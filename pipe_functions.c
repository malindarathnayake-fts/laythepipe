#include <stdio.h>
#include <unistd.h>
#include <string.h>

// Function to write a message to a pipe
__attribute__((visibility("default"))) void writeToPipe(int pipe_fd, const char* message) {
    ssize_t bytes_written = write(pipe_fd, message, strlen(message) + 1);
    if (bytes_written == -1) {
        perror("Error writing to pipe");
        // Handle error (e.g., return or exit)
    }
}

// Function to read a message from a pipe
__attribute__((visibility("default"))) void readFromPipe(int pipe_fd, char* buffer, size_t buffer_size) {
    ssize_t bytes_read = read(pipe_fd, buffer, buffer_size - 1); // Ensure there's room for null terminator
    if (bytes_read == -1) {
        perror("Error reading from pipe");
        // Handle error (e.g., return or exit)
    }
    buffer[bytes_read] = '\0'; // Null-terminate the buffer
}
