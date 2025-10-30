#include <stdio.h>

int main(void) {
    int c;  // use int to handle EOF properly

    // Read one character at a time until EOF
    while (fscanf(stdin, "%c", (char *)&c) == 1) {
        fprintf(stdout, "%c", c);
    }

    return 0;
}
