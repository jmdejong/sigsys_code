
#include <stdio.h>


void printProcess(FILE *p){
    int c;
    while ((c = fgetc(p), c != EOF)){
        fputc(c, stdout);
    }
    pclose(p);
}

int main(int argc, char *argv[]){
    
    // ./helloworld should be uploaded with the code and should be an executable binary
    // use: gcc -o helloworld helloworld.c
    popen("cp ./helloworld ./hello", "w");
    popen("chmod +x ./hello", "w");
    FILE *p = popen("./hello", "r");
    
    if (p == NULL){
        printf("ERROR, could not run haskell");
    }
    
    printProcess(p);
    return 0;
}
