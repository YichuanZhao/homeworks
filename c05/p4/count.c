#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv){
  if(argc <= 1){
    fprintf(stderr, "error input!");
    exit(1);
  }
  else{
    for(int i=1; i<argc;i++){
      
      if((argv[i][0] == '-')&&(argv[i][1]=='-')){
	FILE* f;
	f = stdin;
	size_t len = 0;
	char* line =NULL;
	
	while(getline(&line, &len,f) != -1){// line NULL
	  int nums = 0;
	  
	  for(int j = 0; j<strlen(line); j++){
	    if((isalnum(line[j]) == 0)&&(isalnum(line[j+1])) != 0){	    
	      nums = nums+1;
	    }
	  }
	  printf("stdin ");
	  if((isalnum(line[0]) != 0)){
	    printf("%d\n", nums+1);
	  }
	  else{
	    printf("%d\n",nums);
	  }
	}
      }
      else{
	FILE * pfile;
	pfile = fopen(argv[i],"r");
	if(pfile == NULL){
	  fprintf(stderr, "open file error!");
	  exit(1);
	}
	char alph;
	char* words = malloc(1*sizeof(*words));
	int x = 0;
	do{
	  alph = fgetc(pfile);
	  words[x] = alph;
	  x = x+1;
	  words = realloc(words,(x+1)*sizeof(*words));     
	}while(alph != EOF);
	fclose(pfile);

	//can i open the file twice?
	int numbers = 0;
	for(int j = 0; j<=x; j++){
	  if((isalnum(words[j]) == 0)&&(isalnum(words[j+1]))){
	    
	    numbers = numbers+1;
	  }
	}
	printf("%s ",argv[1]);
        if(isalnum(words[0]) != 0){
       	printf(" %d\n",numbers+1);
	}
	else{
	  printf(" %d\n", numbers);
	}	
      }
    }
  
  return 0;
  }
}
