

#define TRUE 1
#define FALSE 0
#define bool int

typedef struct intArray {
    int length;
    int *values;
} intArray;

intArray createIntArray(int length);
void destroyIntArray(intArray ar);

int intArrayGet(intArray ar, int i);

intArray readIntArray();
void printIntArray();

// bool isEmpty(intArray ar);

intArray emptyIntArray();

bool intArrayEquals(intArray a, intArray b);

