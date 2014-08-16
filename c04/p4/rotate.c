#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char**argv){

  if(argc != 2){
    //fprintf(stderr,"No file name provided!");
    exit(1);
  }
  else{
  FILE *pfile;
  pfile = fopen(argv[1],"r");
  if(pfile==NULL){
    //fprintf(stderr,"open file error!");
    exit(1);
  }
 
  char alph[10][11];

    for(int i = 0; i<=9; i++)
      {
	for(int j = 0; j<=10; j++)
	  {  
            alph[i][j] = fgetc(pfile);
	    //  printf("%c", alph[i][j]);
	    if(alph[i][j]==EOF){
	      //fprintf(stderr, "wrong input!\n");
	      exit(1);
	    }
	    if((alph[i][j] == '\n')&&(0<=j)&&(j<=9)){
	      //fprintf(stderr, "wrong input!\n");
	      exit(1);
	    }
	  }
      } 
    char test = fgetc(pfile);
    if(test != EOF){
      //fprintf(stderr,"wrong input!\n");
      exit(1);
	}

    char newalph[10][11];

    for(int x = 0; x<=9; x++)
      {
	for(int y = 0;y<=9;y++)
	  {
	    newalph[x][y] = alph[9-y][x];
	  }
      }

  for(int x = 0; x<=9; x++)
      {
	for(int y = 0;y<=9;y++)
	  {
	    printf("%c",newalph[x][y]);
	  }
	printf("\n");
      }

  fclose(pfile);   
  }
  return 0;

}
