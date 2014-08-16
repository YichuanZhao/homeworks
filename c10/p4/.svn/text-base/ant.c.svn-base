#include <stdio.h>
#include <stdlib.h>

struct _point_t {
  long x;
  long y;
};

typedef struct _point_t point_t;
typedef point_t vector_t;

//start: the point to start from
//directions: the (backwards) directions (as an array)
//n: how many directions are in the array directions
point_t follow(point_t start, vector_t * directions, int n) {
  if(n == 0){
    printf("Food at (%ld,%ld)\n", start.x, start.y);
    return start;   
  }
  else{
    start.x  = start.x - directions[n-1].x;
    start.y = start.y - directions[n-1].y;
    printf("Go to (%ld,%ld)\n",start.x,start.y);
    
    return follow(start, directions, n-1); 
  }
}

//given a line (e.g. ("3,4") convert it to a vector_t
vector_t lineToPoint(const char * line) {
  vector_t p;
  long int num1, num2;
  char* endnum;
  num1 = strtol(line, &endnum,0);
  num2 = strtol(endnum+1, &endnum, 0);
  p.x = num1;
  p.y = num2;
  return p;
}

//given a FILE *f, read all the lines.
//v is the memory allocated to hold all the previous lines
// (as an array of vector_t)s
//n points at an int, which says how many items are already in v.
//that is *n is the length of v.
// this function will update *n whenever it reads more items,
// so that when it returns to its original caller, the int
// whose address was passed in will indicate the lenght of the
// returned array
vector_t * readVector(FILE * f, vector_t * v, int * n) {
 
  char* line = NULL;
  size_t len = 0;
  if(getline(&line, &len, f)!=-1){
    v = realloc(v, (*n+1)*sizeof(*v));
    v[*n] = lineToPoint(line);
    *n = *n +1;
    free(line);
    return readVector(f, v, n);
  }
  else{
    free(line);
    return v;
  }
}
int main(int argc, char ** argv) {
  if(argc <=1 ){
    fprintf(stderr, "Wrong input!");
    exit(1);
  }
  vector_t* v = malloc(sizeof(*v));
  int num = 0;
  FILE* f;
  f = fopen(argv[1], "r");

  vector_t* v_new = readVector(f, v, &num);
  vector_t start;
  start.x = 0;
  start.y = 0;
  follow(start, v_new, num);
  fclose(f);
  free(v_new);
  return EXIT_SUCCESS;
}
