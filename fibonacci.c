#include<stdio.h>
void fib(int);
main()
{
    FILE *ptr;
    ptr=fopen("fibonnaci.txt","w");
    int n;
    if(ptr==NULL)
    {
        printf("Error in the file opening\n");
        return 1;
    }
    printf("Enter the number\n");
    scanf("%d",&n);
    if(n>2)
        {
             fib(n);
        }
    else if(n==2)
    {
        fprintf(ptr,"0,1");
    }
    else if(n<0)
    {
        fprintf(ptr,"Invalid");
    }
    else if(n==1)
    {
        fprintf(ptr,"0");
    }
    fclose(ptr);
    printf("The reult is stored in fibonacci file\n");
}
void fib(int n)
{
    FILE *ptr;
    ptr=fopen("fibonnaci.txt","w");
    int i;
    int x=0,y=1,z;
    fprintf(ptr,"%d\t",x);
    fprintf(ptr,"%d\t",y);
    for(i=3;i<=n;i++)
    {
        z=x+y;
        fprintf(ptr,"%d\t",z);
        x=y;
        y=z;
    }
    fclose(ptr);
}
