// 1)
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void count() {
  printf("Enter lines of text here: ...\n");
  char c;
  int nc = 0, nt = 0, nbackslash = 0, nl = 0;
  while ((c = getchar()) != EOF) {
  if (c == '\n') { ++nl;
  } else if (c == '\t') { ++nt;
  } else if (c == '\\') { ++nbackslash;
  } else if (isspace(c) != 0) { ++nc; }
  }
  printf("lines: %d\n", nl);
  printf("tabs: %d\n", nt);
  printf("backslashes: %d\n", nbackslash);
  printf("alphanumeric: %d\n", nc);
}
int main(int argc, const char* argv[]) {
  count();
  return 0;
}

// 2)  strchr(s, c)
// 3)  strspn(s, t)
// 4)  exit(1)
// 5)  fopen("midterm.txt", "r")

// 6)
char* strcpy(char* s, const char* t) {
  char* p = s;
  while((*p++ = *t++) != '\0') { }
  return s;
}

// 7)
char* strncat(char* s, const char* t, size_t n) {
  char* p = s;
  while(*p != '\0') {
    ++p;
  }
  while(*t != '\0' && n-- != 0) {
    *p++ = *t++;
  }
  return s;
}

// 8)
int strcmp(const char* s, const char* t) {
  while(*s != '\0' && *t != '\0' && *s == *t) {
    ++s;
    ++t;
  }
  return *s - *t;
}
