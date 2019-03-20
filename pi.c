#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double get_pi();

int main (int argc, char * argv[])
{

  printf("Pi is %f", get_pi());
  return 0;
}

double get_pi(){
  double i;
  double count = 0;
  double sqr = 10000;
  for (i = 0; i < sqr; i++){
      double x = rand()/((double)RAND_MAX);
      double y = rand()/((double)RAND_MAX);
      if (x * x + y * y < 1.0){
          count += 1;
      }
  }
  return (4 * count)/(sqr);
}
