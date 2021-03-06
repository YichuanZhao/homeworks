#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//make a struct for student
struct _student_f{
  char * name;  //name
  char ** classname; //array of class names
  int num_class; // number of classes
};
  
  typedef struct _student_f student_f;


//put classes in the array
char** classarray(char** array_class, char* class_s_names, int* class_n){
  int r_w = 0;
  if(*class_n == 0){
    *class_n = *class_n +1;
    array_class[*class_n -1] = strdup(class_s_names);
  }
  else{
  for(int i=0; i<(*class_n); i++){
    if(strcmp(array_class[i], class_s_names) == 0){
      r_w = 1;     
    }
  }
  if(r_w == 0){
    *class_n = *class_n +1;
    array_class = realloc(array_class, (*class_n)*sizeof(*array_class));
    array_class[(*class_n - 1)] = strdup(class_s_names);
  }
  }
  return array_class;
}

int main(int argc, char **argv){
  if(argc <=1){
    //fprintf(stderr,"Invalid input!\n");
    exit(1);
  }
  else{ 
    FILE* pfile; 
    pfile = fopen(argv[1],"r");  //open the file
    if(pfile == NULL){
      fprintf(stderr, "Open file error!");
      exit(1);
    }
    
    //char* line_t = NULL; //total number of students
    //size_t len_t = 0;
    //getline(&line_t,&len_t,pfile);
    //int total; 
    //for(int i=0; i<strlen(line_t)-1;i++){
    //  if(isdigit(line_t[i])==0){
    //	fprintf(stderr,"Invalid File Format\n");
    //	exit(1);
    //  }
    //}
    //total = atoi(line_t);
    //free(line_t);
    
    //int Zero = 0;
    //int* class_N;
    //class_N = &Zero; 
    char** array_class_names = malloc(sizeof(*(array_class_names)));

    student_f* info = malloc(total*sizeof(*info)); //initialize the array of structs

    //read the file information into the array 
    for(int i = 0; i<total; i++){
      char* line = NULL;
      size_t len = 0;
      getline(&line,&len,pfile);
      //info[i].name = malloc(20*sizeof(*(info[i].name)));
      info[i].name =strdup(line); // get students' names
      free(line);
      char* line_n = NULL;
      size_t len_n = 0;
      getline(&line_n,&len_n,pfile);
      for(int j=0 ;j<strlen(line_n)-1; j++){
	if(isdigit(line_n[j])==0){
	  fprintf(stderr,"Invalid File Format\n");
	  exit(1);
	}
      }

      int n = atoi(line_n);
      free(line_n);
     
      info[i].num_class = n; //num of classes

      info[i].classname = malloc(n*sizeof(*(info[i].classname)));//initialize the classname array in the info 
      
      //read the classnames into the struct
      for(int j = 0; j<n;j++){
	char* line_c = NULL;
	size_t len_c = 0;
	getline(&line_c,&len_c,pfile);
        //info[i].classname[j] = malloc(20*sizeof(*(info[i].classname[j])));
	char* hold_name = malloc((strlen(line_c)-1)*sizeof(*hold_name));
	for(int l = 0; l<(strlen(line_c)-1);l++){
	  hold_name[l] = line_c[l];
	  
	}
	info[i].classname[j] = strdup(hold_name); //read class names
	free(line_c);
	free(hold_name);
        array_class_names = classarray(array_class_names, info[i].classname[j], class_N);
      }
    
    }
    fclose(pfile);
    // create different files based on class names
    for(int i=0;i<*class_N;i++){
      FILE* inf;
      char*c = strdup(array_class_names[i]);
      strcat(c,".roster.txt");
      inf = fopen(c,"r");
      if(inf == NULL){
	inf = fopen(c,"w");
      }
      free(c);
      for(int j=0; j<total;j++){
	for(int k=0; k<info[j].num_class;k++){
	  if(strcmp(info[j].classname[k],array_class_names[i]) == 0){	  
	    fprintf(inf,"%s",info[j].name);    
	  }
	}
      }
      fclose(inf);
    }
    for(int i = 0; i<*class_N;i++){
      free(array_class_names[i]);
    }
    free(array_class_names);
    for(int i = 0;i < total;i++){
      free(info[i].name);
      for(int j=0; j<info[i].num_class;j++){
	free(info[i].classname[j]);
      }
      free(info[i].classname);
    }
    free(info);
    return 0;
  }
}
