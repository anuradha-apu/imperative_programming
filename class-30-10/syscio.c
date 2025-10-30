#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char buf[1024];
    ssize_t n;

  int rfd = open("input.txt", O_RDONLY);
  int wfd = open("oo.txt", O_WRONLY | O_CREAT , 0644);

  while ((n = read(rfd, buf, sizeof(buf))) > 0)
      write(wfd, buf, n);

  close(rfd);
  close(wfd);

}
