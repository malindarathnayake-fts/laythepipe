# FTS 

#!/bin/bash

# Create a pipe
pipe_fd=($(mkfifo myfifo && cat myfifo))

# Prompt the user for input
echo "Enter a message:"
read message

# Call the C function from the shared library to write to the pipe
./libpipe_functions.so $pipe_fd "$message"