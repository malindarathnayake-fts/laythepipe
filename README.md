# pipe_functions.c
# This code defines two functions:

writeToPipe: Writes a message to a pipe.
readFromPipe: Reads a message from a pipe.


# Compile it 

Pre-reqs

Ubuntu
sudo apt install gcc libc6-dev


gcc -shared -fPIC -o libpipe_functions.so pipe_functions.c


# Two sample scripts for Demo purposes included
