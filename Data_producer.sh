# FTS 

#!/bin/bash

# Kill the named pipe if it exists
if [ -p /tmp/Zepipe01 ]; then
    rm /tmp/Zepipe01
fi

# Create a pipe
pipe_fd="/tmp/Zepipe01"
mkfifo $pipe_fd

# Prompt the user for input
echo "Enter a message:"
read message

# Call the C function from the shared library to write to the pipe
./libpipe_functions.so "$pipe_fd" "$message"