#include <stdio.h>

enum states { START, ESCAPE, CR };

#define cLF '\n'
#define cESC '\\'
#define cCR '\r'

int main() {
  int c;
  int state = START;

  while ((c = getchar()) != EOF) {
    switch (state) {
      case ESCAPE:
        putchar(c);
        state = START;
        break;
      case CR:
        if (c == cLF) {
          putchar(c);
          state = START;
        } else if (c == cCR) {
          putchar(cLF);
          state = CR;
        } else if (c == cESC) {
          putchar(cLF);
          putchar(c);
          state = ESCAPE;
        } else {
          putchar(cLF);
          putchar(c);
          state = START;
        }
        break;
      case START:
        if (c == cCR) {
          state = CR;
        } else if (c == cESC) {
          putchar(c);
          state = ESCAPE;
        } else {
          putchar(c);
          state = START;
        }
        break;
    }
  }

  if (state == CR) {
    putchar(cLF);
  }

  return 0;
}
