#include <stdio.h>

#define NOBLANK 'a'
#define IN 1
#define OUT 2

void eight() {
  int nb, nl, nt, c;

  nb = nl = nt = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ')
      ++nb;

    if (c == '\t')
      ++nt;

    if (c == '\n')
      ++nl;

    printf("%d %d %d\n", nb, nl, nt);
  }
}

void nine1() {
  int c, lastc;

  lastc = NOBLANK;

  while ((c = getchar()) != EOF) {
    if (c != ' ') {
      putchar(c);
    }

    if (c == ' ') {
      if (lastc != ' ') {
        putchar(c);
      }
    }

    lastc = c;
  }
}

void nine2() {
  int c, lastc;

  lastc = NOBLANK;

  while ((c = getchar()) != EOF) {
    if (c != ' ') {
      putchar(c);
    } else if (lastc != ' ') {
      putchar(c);
    }
    lastc = c;
  }
}

void nine3() {
  int c, lastc;
  lastc = NOBLANK;

  while ((c = getchar()) != EOF) {
    if (c != ' ' || lastc != ' ')
      putchar(c);

    lastc = c;
  }
}

void ten() {
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\t')
      printf("\\t");
    else if (c == '\b')
      printf("\\b");
    else if (c == '\\')
      printf("\\\\");
    else
      putchar(c);
  }
}

void twelve() {
  int state, c;

  state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == '\t' || c == '\n' || c == ' ') {
      if (state == IN) {
        putchar('\n');
        state = OUT;
      }
    } else if (state == OUT) {
      state = IN;
      putchar(c);
    } else {
      putchar(c);
    }
  }
}
