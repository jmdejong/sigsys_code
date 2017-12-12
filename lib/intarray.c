
#include "intarray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define bool int

void *safeMalloc(int sz) {
  void *p = calloc(sz, 1);
  if (p == NULL) {
    fprintf(stderr, "Fatal error: safeMalloc(%d) failed.\n", sz);
    exit(EXIT_FAILURE);
  }
  return p;
}

intArray createIntArray(int length){
    
    intArray ar;
    ar.length = length;
    ar.values = safeMalloc(sizeof(int) * length);
    return ar;
}

void destroyIntArray(intArray ar){
    free(ar.values);
}

int intArrayGet(intArray ar, int i){
    if (i<0 || i >= ar.length){
        return 0;
    }
    return ar.values[i];
}


intArray readIntArray(){
    int len;
    int *x;
    char c;
    scanf("%d:", &len);
    x = calloc(len, sizeof(int));
    do {
        c = getchar();
    } while (c != '[');
    if (len > 0) {
        scanf("%d", &x[0]);
        for (int i=1; i < len; i++){
            scanf(",%d", &x[i]);
        }
    }
    do {
        c = getchar();
    } while (c != ']');
    intArray ar;
    ar.length = len;
    ar.values = x;
    return ar;
}

void printIntArray(intArray ar) {
    printf("%d: [", ar.length);
    if (ar.length > 0) {
        printf("%d", ar.values[0]);
        for (int i=1; i<ar.length; i++) {
            printf(",%d", ar.values[i]);
        }
    }
    printf("]\n");
}

intArray emptyIntArray(){
    intArray ar;
    ar.length = 0;
    ar.values = NULL;
    return ar;
}

bool intArrayEquals(intArray a, intArray b){
    if (a.length != b.length){
        return FALSE;
    }
    for (int i=0; i < a.length; i++){
        if (a.values[i] != b.values[i]){
            return FALSE;
        }
    }
    return TRUE;
}


bool isEmpty(intArray ar){
    return ar.length == 0;
}
