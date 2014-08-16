#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main(int argc, char ** argv)
{
  if(argc != 3 ){
    fprintf(stderr,"Wrong Inputs!\n");
    exit(1);
  }
  else{
  //read a file 
  FILE *pfile;   
  pfile = fopen(argv[1],"r");
  if(pfile==NULL){
    fprintf(stderr,"open file error!");
    exit(1);
  }

  // enter the key 
  int key;
  if((argv[2][0] == '-')&&(strlen(argv[2])>=2)){
    for(int i=1; i<strlen(argv[2]);i++){
      if((argv[2][i]>57)||(argv[2][i]<48)){
	fprintf(stderr,"Invalid Password!\n"); 
	exit(1);  
      }
    }
  }
  else if((argv[2][0] == '-')&&(strlen(argv[2])==1)){
    fprintf(stderr,"Invalid Password!\n");
    exit(1);
  }
  else{
    for(int j=0 ;j<strlen(argv[2]);j++){
      if((argv[2][j]>57)||(argv[2][j]<48)){
	fprintf(stderr,"Invalid Password!\n"); 
	exit(1);  
      }    
    }
  } 
key = atoi(argv[2]);
  // encryt file
 char alph;
 do{
   alph = fgetc(pfile);
   if(alph != EOF){
   if((isalpha(alph)) != 0){
     alph = tolower(alph);
     if((key+alph-96)%26 > 0){
       alph = (alph -96 + key)%26 + 96;
     }
     else{
       alph = ((alph -96 + key)%26 +122);
     }
   } 
     printf("%c", alph);
   }
 }while(alph != EOF);
 //printf("\n");
 int r;
 r = fclose(pfile);
 if(r == EOF){
   fprintf(stderr,"close file error!");
   exit(1);
 }
  }
  return 0;
}
/* int main(){ */
/*   char a = tolower('a'); */
/*   printf("%c",a); */
/*   return 0; */
/* } */

