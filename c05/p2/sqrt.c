#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define ERROR_LIMIT 0.0000001

double mySqrt(double x) {
  if (x < 0) {
    //sqrt(negative) is not a number
    //we'll do negative not a nubmer
    //to be consistent with the C library
    //Note that this case is NOT the problem
    return -nan("");
  }
  //guess x/2 and work from there
  double guess = x / 2;
  //we're going to iteratively revise this guess.
  //we'll stop when the guess is "close enough"
  //that is, when we square the guess, and are
  //within ERROR_LIMIT of x.
  int k = 0;
  while (((fabs(x - guess * guess)) > ERROR_LIMIT)&&(k<=100000)) {
    //take that error
    double error = x - guess * guess;
    //and adjust the guess accordingly
    guess += error / (2*guess);
    k = k+1;
  }
  //return the guess after we got it close enough
  return guess;
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    fprintf(stderr,"Useage: sqrt number\n");
    return EXIT_FAILURE;
  }
  double x = atof(argv[1]);
  double ans = mySqrt(x);
  printf("mySqrt(%f) = %f\n",x,ans);
  printf("  sqrt(%f) = %f\n",x, sqrt(x));
  return EXIT_SUCCESS;
}
