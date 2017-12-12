#include <stdio.h>


void printProcess(FILE *p){
    int c;
    while ((c = fgetc(p), c != EOF)){
        fputc(c, stdout);
    }
    pclose(p);
}

int main(int argc, char *argv[]){
    
    FILE *p = popen("ls /usr/bin/", "r");
    
    printProcess(p);
    
    return 0;
}
