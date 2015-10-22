#include <stdlib.h>

int binsearch1(int *arr, size_t len, int key) {
  size_t l=0, u=len;

  while(l <= u) {
    size_t m = (size_t)((l+u)/2);
    if      (arr[m] < key) l = m;
    else if (arr[m] > key) u = m;
    else return m;
  }
  
  return -1;
}
