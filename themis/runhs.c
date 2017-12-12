#include <stdio.h>


/* Earlier test, but it got messy
 */

void printProcess(FILE *p){
    int c;
    while ((c = fgetc(p), c != EOF)){
        fputc(c, stdout);
    }
    pclose(p);
}

int main(int argc, char *argv[]){
    
//     char filename[] = "linearfilter";
    
//     char sourceFile[] = sprintf("%s.hs", filename);
    
//     char compileCommand[256];
//     sprintf(compileCommand, "ghc -dynamic %s.hs", filename);
//     popen(compileCommand, "r");
    
//     char runCommand[256];
//     sprintf(runCommand, "./%s", filename);
    popen("cp ./linearfilter ./filter", "w");
//     printProcess(popen("ls -al .", "r"));
    popen("chmod +x ./filter", "w");
    FILE *p = popen("./filter", "r");
    
    if (p == NULL){
        printf("ERROR, could not run haskell");
    }
    
    printProcess(p);
//     int c;
    
//     while ((c = fgetc(p), c != EOF)){
//         fputc(c, stdout);
//     }
//     pclose(p);
    return 0;
}
