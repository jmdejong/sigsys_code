
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

uint powmod(uint base, uint exponent, uint prime) {
  /* This function computes: base raised to the power exponent modulus prime
   * in math notation: (base^exponent) mod prime
   */
  uint pm = 1;
  base = base%prime;
  while (exponent > 0) {
    if (exponent%2 == 1) { /* exponent is odd */
      pm = (pm*base)%prime;
    }
    exponent /= 2;
    base = (base*base)%prime;
  } 
  return pm;
}


void *safeMalloc(int sz) {
  void *p = calloc(sz, 1);
  if (p == NULL) {
    fprintf(stderr, "Fatal error: safeMalloc(%d) failed.\n", sz);
    exit(EXIT_FAILURE);
  }
  return p;
}

bool isPowerOfTwo(uint val){
    if (val == 0){
        return FALSE;
    }
    while ((val & 1) == 0){
        val >>= 1;
    }
    val >>= 1;
    return !val;
}


void printArray(uint *ar, int length) {
    printf("%d: [", length);
    if (length > 0) {
        printf("%u", ar[0]);
        for (int i=1; i<length; i++) {
            printf(",%u", ar[i]);
        }
    }
    printf("]\n");
}

int *readSignal(int *len) {
    int *x;
    char c;
    scanf("%d:", len);
    x = calloc(*len, sizeof(int));
    do c = getchar(); while (c != '[');
    if (len > 0) {
        scanf("%d", &x[0]);
        for (int i=1; i < *len; i++) scanf(",%d", &x[i]);
    }
    do c = getchar(); while (c != ']');
    return x;
}


// actual modulo that will always return a positive number
int mod(int a, int b){
    int x = a % b;
    if (x < 0){
        x += b;
    }
    return x;
}

int nextPowerOfTwo(int x){
    int y = 1;
    // won't end when 2*x > INT_MAX
    while (y < x){
        y *= 2;
    }
    return y;
}


int max(int a, int b){
    return a>b ? a : b;
}

// integer log2
uint log2i(uint x){
    uint l = 0;
    while (x >>= 1){
        l++;
    }
    return l;
}
