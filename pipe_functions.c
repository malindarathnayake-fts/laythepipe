#include <stdio.h>
#include <unistd.h>
#include <string.h>

// Function to write a message to a pipe
__attribute__((visibility("default"))) void writeToPipe(int pipe_fd, const char* message) {
    // Write the message to the pipe
    write(pipe_fd, message, strlen(message) + 1);
}

// Function to read a message from a pipe
__attribute__((visibility("default"))) void readFromPipe(int pipe_fd, char* buffer, size_t buffer_size) {
    // Read from the pipe into the buffer
    read(pipe_fd, buffer, buffer_size);
}

// compile notes
//gcc -shared -fPIC -o libpipe_functions.so pipe_functions.c
