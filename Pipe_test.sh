# Create a pipe
#mkfifo "/tmp/Zepipe01"


echo "Enter a message:"
read message

echo "...----------...."

echo "$message" > "/tmp/Zepipe01" &
echo "Reading from pipe..."
cat "/tmp/Zepipe01"
