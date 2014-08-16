#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct _a_struct {
  int x;
  int numStrs;
  char ** strs;
};
typedef struct _a_struct a_struct;


int main(void) {
  const char * strs[] = {"abc",
			 "def",
			 NULL};
  a_struct * a;
  a_struct * b;
  int i = 0;
  a = malloc(sizeof(*a));
  a->x = 3;
  a->numStrs = 0;
  a->strs = NULL;
  b = a;
  while (strs[i] != NULL) {
    b->numStrs ++;
    b->strs = realloc(b->strs, b->numStrs * sizeof(*b->strs));
    b->strs[b->numStrs - 1 ] = strdup(strs[i]);
    i++;
  }
  for (i = 0; i < a->numStrs; i++) {
    printf("%s\n", a->strs[i]);
    free(a->strs[i]);
  }
  free(a->strs);
  free(a);
  a = NULL;
  b = NULL;
  return EXIT_SUCCESS;
}
