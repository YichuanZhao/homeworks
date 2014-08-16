#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char**argv){

  if(argc != 2){
    printf("Wrong inputs\n");
  }
  else{
  FILE *pfile;
  int array[26] = {0};
  char alph;
  int num;

  // read from file, to count which is most common
  pfile = fopen(argv[1],"r");

  if(pfile==NULL){
    fprintf(stderr,"open file error!");
    exit(1);
  }
 
  do{
    alph = fgetc(pfile);

    if((isalpha(alph)) != 0){  
      alph = tolower(alph);   
      num = (int)(alph - 97);
      /*printf("%d\n", num);*/ //for test
      array[num] = array[num]+1;
      }
  }while(alph != EOF);
  /*printf("%d\n", array[3]);*/ //for test
  fclose(pfile);
  // find out the position of the most common character 
  //and then find the key
  int key = 0;
  for(int i=0; i<=25; i++)
    {
      if(array[key] < array[i]){
       
        key = i;
      }
      /* printf("%d",array[i]);*/ //for test
    }
  key = key - 4;
  printf("The key is %d\n",key);
 
  /*// print the breaked file
  char al;
  pfile = fopen(filename, "r");
  do{
     al = fgetc(pfile);
    if((al != EOF)&&(isalpha(al))){
      if((al-key-96) > 0){
	al = al-(key);
       
      }
      else{
	al = al - key +26;
    }
      printf("%c", al);
    }

  }while(al != EOF);
  printf("\n");
  fclose(pfile);
  */
  }
  return 0;

}
