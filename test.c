#include<stdio.h>
#include<stdlib.h>

char* reverse (char *c) {
  printf("%s\n", c);
  int n = 0;
  while(c[n]) {
    n++;
  };
  char *r;
  r = (char*)calloc(n+1, sizeof(char));
  int p = 0, i = 0;
  for (i=n-1; i>=0; i--) {
    printf("%c ", c[i]);
    r[p++] = c[i];
  }
  r[p] = '\0';
  return r;
}

int main() {
  char *c = "test";
  char *r = reverse(c);
  printf("%s\n", r);
}
