#include <stdio.h>

#define TABINC 8

void detab() {
  int c, nb, pos;
  nb = 0;
  pos = 1;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      nb = TABINC - (pos - 1) % TABINC;
      while (nb > 0) {
        putchar(' ');
        ++pos;
        --nb;
      }
    } else if (c == '\n') {
      putchar(c);
      pos = 1;
    } else {
      putchar(c);
      ++pos;
    }
  }
}

int main(int argc, char* argv[]) { printf("hello, world\n"); }
