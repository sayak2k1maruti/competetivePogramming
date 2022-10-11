#include <stdio.h>
main()
{
 FILE*fp;
struct emp
{
   char name[40];
   int age;
   float bs;
};
   struct emp e;
   fp=fopen("EMPLOYEE.DAT","r");
   if(dp=NULL)
   {
    puts("Cann not open file");
    exit();
    }
    while(fscan (fp,"%s %d %f", e.name, &e.age, &e.bs)!=EOF)
     printf("\n%s %d %f", e.name,e.age, e.bs);
     fclose(fp);
     
}
     