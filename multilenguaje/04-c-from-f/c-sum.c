#include <stdlib.h>
#include "c-sum.h"

int sum_abs_(int *in, int *num, int *sum) {
   int i;
    
   *sum=0;
   for (i=0; i < *num; ++i) {
       *sum += abs(in[i]);
   }
   return 0;
}
 
