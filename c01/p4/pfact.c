#include <stdio.h>
#include <stdlib.h>


void printFactors(int n) {
  
 if( n < 0)
    {
      printf("we want a positive integer");
    }
  else if (n == 1)
    {
      printf("\n");
    }
  else
    {
      int k = 2;
      while(k<n)
	{
	  if(n%k == 0)
	    {
	      printf("%d *",k);
	      n = n/k;
	    }
	  else
	    {
	      if(k == 2)
		{
		  k = 3;
		}
	      else
		{
		  k = k + 2;
		}
	    }
	}
      printf("%d\n",k);
    }
}

int main(void) {
  printf("Factorization of 1:\n");
  printFactors(1);
  printf("Factorization of 60:\n");
  printFactors(60);
  printf("Factorization of 132:\n");
  printFactors(132);
  printf("Factorization of 11726:\n");
  printFactors(11726);
  printf("Factorization of 2169720:\n");
  printFactors(2169720);
  printf("Factorization of 1789220887:\n");
  printFactors(1789220887);
  return EXIT_SUCCESS;
}
