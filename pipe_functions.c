#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

// Function to write a message to a pipe
__attribute__((visibility("default"))) bool writeToPipe(int pipe_fd, const char* message) {
    ssize_t bytes_written = write(pipe_fd, message, strlen(message) + 1);
    if (bytes_written == -1) {
        perror("Error writing to pipe");
        return false; // Return false to indicate failure
    }
    if (bytes_written != strlen(message) + 1) {
        fprintf(stderr, "Partial write occurred.\n");
        return false; // Return false to indicate partial write
    }
    return true; // Return true to indicate success
}

// Function to read a message from a pipe
__attribute__((visibility("default"))) bool readFromPipe(int pipe_fd, char* buffer, size_t buffer_size) {
    if (buffer_size == 0) {
        fprintf(stderr, "Buffer size must be greater than 0.\n");
        return false; // Return false if buffer size is invalid
    }

    ssize_t bytes_read = read(pipe_fd, buffer, buffer_size - 1); // Ensure there's room for null terminator
    if (bytes_read == -1) {
        perror("Error reading from pipe");
        return false; // Return false on read error
    }
    if (bytes_read == 0) {
        fprintf(stderr, "End of file reached or pipe closed by writers.\n");
        return false; // Return false on EOF or closed pipe
    }

    buffer[bytes_read] = '\0'; // Null-terminate the buffer
    return true; // Return true to indicate success
}