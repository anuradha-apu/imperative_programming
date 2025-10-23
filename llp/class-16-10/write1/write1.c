#include <unistd.h> // Required for the write() function
#include <string.h> // Required for strlen()

int main() {
    const char *message = "Hello, world!\n";
    // Write the string to stdout (file descriptor 1)
    write(1, message, strlen(message)); 
    return 0;
}
