#include <stdio.h>

/*
 * Execute a python program (with hardcoded path)
 * 
 * stdin and stdout are basically piped
 */




void printProcess(FILE *p){
    // print all output from a process on stdout
    // close the process when it is done
    int c;
    while ((c = fgetc(p), c != EOF)){
        fputc(c, stdout);
    }
    pclose(p);
}

int main(int argc, char *argv[]){
    
    // change this shell command to run another process
    FILE *p = popen("python3 helloworld.py", "r");
    
    if (p == NULL){
        printf("ERROR, could not run python");
    }
    
    printProcess(p);
    
    return 0;
}
