#include <stdlib.h>
#include <stdio.h>

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


int binsearch2(int *arr, size_t len, int key) {
  size_t l=0, u=len;

  while(l <= u) {
    size_t m = (size_t)((l+u)/2);
    if      (arr[m] < key) l = m+1;
    else if (arr[m] > key) u = m-1;
    else return m;
  }
  
  return -1;
}

int binsearch3(int *arr, size_t len, int key) {
  if(len > 0) {
    size_t l=0, u=len-1;

    while(l <= u) {
      size_t m = (size_t)((l+u)/2);
      if      (arr[m] < key) l = m+1;
      else if (arr[m] > key) u = m-1;
      else return m;
    }
  }
  
  return -1;
}



/* int main() { */
/*   int arr[5] = {10,20,30,40,50}; */
/*   printf("Res: %d\n", binsearch3(arr, 5, 10)); */
/*   printf("Res: %d\n", binsearch3(arr, 5, 50)); */
/*   printf("Res: %d\n", binsearch3(arr, 5, 40)); */
/*   printf("Res: %d\n", binsearch3(arr, 5, 100)); */
/*   printf("Res: %d\n", binsearch3(arr, 0, 10)); */
/*   return 0; */
/* } */
