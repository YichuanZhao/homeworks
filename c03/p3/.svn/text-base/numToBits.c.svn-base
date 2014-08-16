#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int getNthBit(uint32_t number, int bit) {
  if (bit <0 || bit >= 32) {
    printf("Bit %d is invalid\n", bit);
    exit (EXIT_FAILURE);
  }
  return (number & (1<<bit)) != 0;
}

int power(int i, int j)
{
  int num = i;
  if(j == 0)
    {
      num = 1;
    }
  else
    {
  for(int x=1; x<j; x++)
    {
      num = num*i;
    }
    }
  return num;
}

void numToBits(uint32_t * nums, int nNums, int * bits, int nBits) {
  int numarray[32];
  if(nNums*32 > nBits)
    {
      printf("Invalid call to numToBits! nBits is %d, nNums is %d\n", nBits, nNums);
    }
  else
    {
      for(int j = 1; j<=nNums; j++)
    {
      numarray[j-1] = nums[j-1];/*pull number out to numarray*/
      for(int i = 31; i>=0;i--)
	{
          
          if(getNthBit(numarray[j-1],i) == 1)
	    {
	      bits[(31-i)+(j-1)*32] = 1;
	    }
	  else
	    {
	      bits[(31-i)+(j-1)*32] = 0;
	    }

          /*if(num[j-1] >= power(2,i))
              {
           
              numarray[j-1] = numarray[j-1] - power(2,i);
	      bits[(31-i)+(j-1)*32] = 1;
	    }
	    else
	    {
	      bits[(31-i)+(j-1)*32] = 0;
	      } */
	 
	}
     
    }
    }   
}

void doTest(uint32_t * nums, int n) {
  int bits[n *32];
  numToBits(nums, n, bits, n*32);
  for (int i =0; i < n; i++) {
    printf(" %9d (%8X) => ", nums[i], nums[i]);
    for (int j = 0; j < 32; j++) {
      printf("%d", bits[i*32 + j]);
    }
    printf("\n");
  }
}

int main(void) {
  uint32_t array1[] = { 1, 2, 3, 4, 5, 15, 109};
  uint32_t array2[] = { 123456789, 987654321 };
  int bits[7*32-1];
  doTest (array1, 7);
  doTest (array2, 2);
  numToBits(array1,7, bits , 7*32-1);
  return EXIT_SUCCESS;
}
