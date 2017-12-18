

#define TRUE 1
#define FALSE 0
#define bool int

typedef unsigned int uint;

uint powmod(uint base, uint exponent, uint prime);

void *safeMalloc(int sz);

bool isPowerOfTwo(uint val);

void printArray(uint *ar, int length);

int *readSignal(int *len);

int mod(int a, int b);

int nextPowerOfTwo(int x);

int max(int a, int b);

uint log2i(uint x);
