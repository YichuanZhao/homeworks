#include<stdlib.h>
#include<stdio.h>

int isPerfect(int x)
{
  int k = 0;
  int result = 0;
  if(x == 1)
    {
      k =1;
    }
  else
    {
   for(int i = 1; i<=x/2; i++)
    {
      if(x%i == 0)
	{
           k = k+i;
	}
    }
    }

  if(k==x)
    {
      result = 1;
    }
  else
    {
      result = 0;
    }

  return result;
}


int main()
{
  int x = 0;
  for (int i = 2; i<=10000; i++)
    {
      x = isPerfect(i);
      if(x == 1 )
	{
	  printf("%d is perfect!\n",i);
	}

    }
  return 0;
}
