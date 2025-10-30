#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char buf[1024];
  size_t n;
  FILE *fp1 = fopen("input.txt", "rb");
  FILE *fp2 = fopen("output.txt", "w");
    while ((n = fread(buf, 1, sizeof(buf), fp1)) > 0) {
        fwrite(buf, 1, n, fp2);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
