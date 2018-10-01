/*
 * unixlines filters input to ensure unix line end conventions.
 * Text lines in unix end with the new line character (LF, \012).
 * Text lines on other platforms end with carriage return (CR, \015) or
 * CRLF (\015\012). Both are changed to new lines. However, escaped carriage
 * returns are not modified.
 */

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
