#include <stdio.h>
#include <stdlib.h>
struct _s1 {
  int a;
  int b;
};
typedef struct _s1 s1;

struct _s2 {
  int n;
  s1 ** p;
};
typedef struct _s2 s2;

int main(void) {
  s2 * x;
  
  x =malloc(sizeof(*x));//WRITE ME
  x->n = 3;//WRITE ME
  x->p = malloc((x->n)*sizeof(*(x->p)));//WRITE ME
  for (int i = 0; i < x->n; i++) {
    x->p[i] = malloc(sizeof(*x->p[i]));//WRITE ME
    x->p[i]->a = i+2;//WRITE ME
    x->p[i]->b = 42-7*i;//WRITE ME
  }
  for (int i = 0; i < x->n; i++) {
    printf("%d\n", x->p[i]->a + x->p[i]->b);
    free(x->p[i]);//WRITE ME
  }
  free(x->p);//WRITE ME
  free(x);//WRITE ME
  return EXIT_SUCCESS;
}
