# C Programming Language

## exercise 1-20

```c
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
```
