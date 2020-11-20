#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


int main (int argc, char* argv[]) {
  
   FILE* fp = fopen("final.test","r");
   int a = 0;
   int c;
   int getlines = 0;
   char* buffer[200];
   char numline[100];
   
   //if (strcmp(argv[1], "-help") == 0){

       //printf("This program will calculate the factorial of a number.");

   //}

    while(fgets(numline, sizeof numline, fp)!=NULL) {

        buffer[a]=malloc(sizeof(numline));
        strcpy(buffer[a], numline);
        a++;
        getlines++;
        
    }

    for( int a = 0; a < getlines; a++){

        if (strcmp(buffer[a] , "Starting\n") == 0){
            buffer[a] = "int main(int argc, char* argv[]) {\n";
        }
        if (strcmp(buffer[a], "  Declaring_first_variable\n") == 0){
            buffer[a] = " int a = 1;\n";
        }
        if (strcmp(buffer[a], "  Declaring_second_variable\n") == 0){
            buffer[a] = " int b = 1;\n";
        }
        if (strcmp(buffer[a], "  Declaring_third_variable\n") == 0){
            buffer[a] = " int c = 1;\n";
        }
        if (strcmp(buffer[a], "  EXIT_PROGRAM\n") == 0){
            buffer[a] = "  return EXIT_SUCCESS;\n";
        }
        if (strcmp(buffer[a], "  Loop_numbers\n") == 0){
            buffer[a] = "  for (a = 1; a <= b; a++)\n";
        }
    }

    FILE* fo = fopen("final.c","w");      
    for (int a = 0; a < getlines; a++){
        
        fprintf(fo,"%s", buffer[a]);

    }

    for (int a = 0; a <getlines; a++){

        free(buffer[a]);

    }

    fclose(fp);
    fclose(fo);
   
    return EXIT_SUCCESS;   


}