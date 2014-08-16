#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

long power(long x, long y) {
  if(y<=0){
    return 1;  
  }
  else{
    return x*power(x,y-1);
  }//write me
}

int main() {
  FILE* f;
  f = stdin;
  if(f == NULL){
    fprintf(stderr,"error input!");
    exit(1);  
  }
  char* line = NULL;
  size_t len =0;   
  while(getline(&line,&len,f)!=-1){
    long int num1, num2;
    char* endnum;
    num1 = strtol(line,&endnum,0);
    num2 = strtol(endnum+1,&endnum,0);
    if((num1==0)&&(num2==0)){
      printf("Wrong Input!");
    }
    
    printf("%ld\n", power(num1,num2));
    
  }
  free(line);
  //write me
  return EXIT_SUCCESS;
}
