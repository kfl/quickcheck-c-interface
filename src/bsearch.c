/*
 * Warning: buggy code ahead. Use with care.
 */
#include <stdlib.h>
#include <stdio.h>


/* BUGGY, may result in infinite loop */
int binsearch1(int *arr, size_t len, int key) {
  size_t lower=0, upper=len;

  while(lower <= upper) {
    size_t m = (size_t)((lower+upper)/2);
    if      (arr[m] < key) lower = m;
    else if (arr[m] > key) upper = m;
    else return m;
  }

  return -1;
}



/* BUGGY, try an empty array */
int binsearch2(int *arr, size_t len, int key) {
  size_t lower=0, upper=len;

  while(lower <= upper) {
    size_t m = (size_t)((lower+upper)/2);
    if      (arr[m] < key) lower = m+1;
    else if (arr[m] > key) upper = m-1;
    else return m;
  }

  return -1;
}

/* BUGGY, try an array with one element */
int binsearch3(int *arr, size_t len, int key) {
  if(len > 0) {
    size_t lower=0, upper=len-1;

    while(lower <= upper) {
      size_t m = (size_t)((lower+upper)/2);
      if      (arr[m] < key) lower = m+1;
      else if (arr[m] > key) upper = m-1;
      else return m;
    }
  }

  return -1;
}

/* Mostly correct, if we ignore huge arrays sizes which may result is integer overflow errors */
int binsearch4(int *arr, size_t len, int key) {
  int lower=0, upper=len-1;

  while(lower <= upper) {
    size_t m = (upper-lower)/2 + lower;
    if      (arr[m] == key) return m;
    else if (arr[m] < key)  lower = m+1;
    else                    upper = m-1;
  }

  return -1;
}

/* BUGGY. Attempt at implementing deferred equality check. See binsearch6 instead.
 */
int binsearch5(int *arr, size_t len, int key) {
  int lower=0, upper=len-1;
  size_t m;

  while(lower < upper) {
    m = (upper-lower)/2 + lower;
    if (arr[m] < key) lower = m+1;
    else              upper = m-1;
  }

  if (arr[m] == key) return m;
  else return -1;
}


/* BUGGY, try an array with one element. Don't uninialized variables. See binsearch7
 */
int binsearch6(int *arr, size_t len, int key) {
  int lower=0, upper=len-1;
  size_t m;

  while(lower < upper) {
    m = (upper-lower)/2 + lower;
    if (arr[m] < key) lower = m+1;
    else              upper = m-1;
  }

  printf("%d %d %zupper\n", lower, upper, m);
  if (lower == upper && arr[m] == key) return m;
  else return -1;
}


/* BUGGY, try an array with two elements, which both have the same value
 */
int binsearch7(int *arr, size_t len, int key) {
  int lower=0, upper=len-1;
  size_t m = lower;

  while(lower < upper) {
    m = (upper-lower)/2 + lower;
    if (arr[m] < key) lower = m+1;
    else              upper = m-1;
  }

  if (lower == upper && arr[m] == key) return m;
  else return -1;
}


/* As correct as binsearch4, but with deferred equality check. The
   deferred equality check means that we'll gain the property that the
   returned index is always the smallest index, even if we have
   duplicated elements in the array.
 */
int binsearch8(int *arr, size_t len, int key) {
  int lower=0, upper=len-1;

  while(lower < upper) {
    size_t m = (upper-lower)/2 + lower;
    if (arr[m] < key) lower = m+1;
    else              upper = m;
  }

  if (lower == upper && arr[lower] == key) return lower;
  else return -1;
}



/* int main() { */

/*   { */
/*     int arr[5] = {10,20,30,40,50}; */
/*     printf("Res: %d expected %d\n", binsearch8(arr, 5, 10), 0); */
/*     printf("Res: %d expected %d\n", binsearch8(arr, 5, 50), 4); */
/*     printf("Res: %d expected %d\n", binsearch8(arr, 5, 40), 3); */
/*     printf("Res: %d expected %d\n", binsearch8(arr, 5, 100), -1); */
/*     printf("Res: %d expected %d\n", binsearch8(arr, 0, 10), -1); */
/*   } */


/*   // Test-cases found by QuickCheck */
/*   { */
/*     int arr[1] = {0}; */
/*     printf("Res: %d\n", binsearch8(arr, 1, -1)); */
/*   } */

/*   { */
/*     int arr[1] = {0}; */
/*     printf("Res: %d\n", binsearch8(arr, 1, 0)); */
/*   } */

/*   { */
/*     int arr[2] = {0,0}; */
/*     printf("Res: %d\n", binsearch8(arr, 2, 0)); */
/*   } */

/*   return 0; */
/* } */
