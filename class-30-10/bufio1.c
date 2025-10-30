#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char buf[1024];
  size_t n;
  FILE *fp = fopen("input.txt", "rb");

    while ((n = fread(buf, 1, sizeof(buf), fp)) > 0) {
        fwrite(buf, 1, n, stdout);
    }

    fclose(fp);
    return 0;
}
