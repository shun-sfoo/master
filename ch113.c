#include <stdio.h>

#define MAXHIST 15
#define MAXWORD 11

#define IN 1
#define OUT 0

int main() {
  int c, i, nc, state;
  int len;
  int maxvalue;
  int overflow;
  int wl[MAXWORD];

  state = OUT;
  nc = 0;
  overflow = 0;
  for (i = 0; i < MAXWORD; ++i) wl[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\t' || c == '\n' || c == ' ') {
      state = OUT;
      if (nc > 0) {
        if (nc < MAXWORD) {
          ++wl[nc];
        } else {
          ++overflow;
        }
      }
      nc = 0;
    } else if (state == OUT) {
      state = IN;
      nc = 1;
    } else {
      ++nc;
    }
  }

  maxvalue = 0;
  for (i = 1; i < MAXWORD; ++i)
    if (wl[i] > maxvalue) maxvalue = wl[i];

  for (i = 1; i < MAXWORD; ++i) {
    printf("%5d - %5d : ", i, wl[i]);
    if (wl[i] > 0) {
      if ((len = wl[i] * MAXHIST / maxvalue) <= 0) len = 1;
    } else
      len = 0;

    while (len > 0) {
      putchar('*');
      --len;
    }
    putchar('\n');
  }

  if (overflow > 0) printf("There are %d words >= %d\n", overflow, MAXWORD);
}
