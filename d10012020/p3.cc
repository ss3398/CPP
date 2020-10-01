#include <string>
#include <iostream>
#include <tclap/CmdLine.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

 
int  main() {
   FILE *fp1, *fp2;
   char a;
 
   fp1 = fopen("in.txt", "r");
   if (fp1 == NULL) {
      puts("cannot open this file");
      exit(1);
   }
 
   fp2 = fopen("out.txt", "w");
   if (fp2 == NULL) {
      puts("Not able to open this file");
      fclose(fp1);
      exit(1);
   }
 
   do {
      a = fgetc(fp1);
      a = toupper(a);
      fputc(a, fp2);
   } while (a != EOF);
 
   fclose(fp1);
   fclose(fp2);
}
