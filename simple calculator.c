#include<stdio.h>
main()
{
    FILE *ptr;
    ptr=fopen("simple calculator.txt","w");
    if(ptr==NULL)
    {
        printf("Error in the file opening\n");
        return 1;
    }
    float x,y,res;
    char op;
    printf("enter the values and operator\n");
    scanf("%f%f%*c%c",&x,&y,&op);
    switch(op)
    {
        case'+':res=x+y;
              fprintf(ptr,"x=%f\ty=%f\nx+y=%f",x,y,res);
              break;
        case'-':res=x-y;
              fprintf(ptr,"x=%f\ty=%f\nx-y=%f",x,y,res);
              break;
        case'*':res=x*y;
              fprintf(ptr,"x=%f\ty=%f\nx*y=%f",x,y,res);
              break;
        case'/':res=x/y;
             if(y==0)
             {
               fprintf(ptr,"error\n");
               break;
             }
             else
             {
                 res=x*y;
                 fprintf(ptr,"x=%f\ty=%f\nx*y=%f",x,y,res);
                 break;
             }
         case'%':(int)x%(int)y;
                fprintf(ptr,"x=%f\ty=%f\nx%y=%f",x,y,res);
                break;
    }
    fclose(ptr);
    printf("The result is stored in simple calculator file\n");
}

