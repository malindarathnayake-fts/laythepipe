# Read Pipe using the SO file

import ctypes
import datetime
import os

# Load the shared library
mylib = ctypes.CDLL('./libpipe_functions.so')

# Define function prototypes
write_func = ctypes.CFUNCTYPE(None, ctypes.c_int, ctypes.c_char_p)
read_func = ctypes.CFUNCTYPE(None, ctypes.c_int, ctypes.c_char_p, ctypes.c_size_t)

# Get function references
c_write = write_func(mylib.writeToPipe)
c_read = read_func(mylib.readFromPipe)

# Create a pipe
pipe_fd = os.open("myfifo", os.O_RDONLY)

def display_message():
    buffer_size = 1024
    buffer = ctypes.create_string_buffer(buffer_size)
    c_read(pipe_fd, buffer, buffer_size)
    message = buffer.value.decode()
    date = datetime.datetime.now().strftime("%Y-%m-%d")
    print(f"{date} - Piped message is - ${message}$")

while True:
    display_message()