#include <stdio.h>
 
int main()
{
   FILE *fp = NULL;
 
   fp = fopen("file_write_1.txt", "w+");
   fprintf(fp, "This is testing for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fclose(fp);
}

