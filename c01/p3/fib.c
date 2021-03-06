#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
  int ans = 0;
  if (n<=0)
    {
      ans = 0;
    }
  else if (n == 1)
    {
      ans = 1;
    }
  else
    {
      ans = fib(n-1) + fib(n-2);
    }
  return ans;
}

int main()
{
  for (int i = -2; i <= 30; i++)
    {
      int fibnumber;
      fibnumber = fib(i);
      printf("fib(%d) = %d\n",i,fibnumber);
    }
  return 0;
} 
