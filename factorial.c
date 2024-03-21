
#include<Stdio.h>
int factorial(int);
int main()
{
    FILE *ptr;
     int n,f;
    ptr=fopen("factorial.txt","r+");
    if(ptr==NULL)
    {
       fprintf(ptr,"Error in the file opening\n");
       return 1;
    }
    fscanf(ptr,"%d",&n);
    if(n>0)
    {
        f=factorial(n);
        fprintf(ptr,"\n%d!=%d",n,f);
    }
    else
        fprintf(ptr,"Invalid input\n");
    fclose(ptr);
}
int factorial(int n)
{
    int i,f=1;
    for(i=1;i<=n;i++)
    {
        f=f*i;
    }
    return f;
}
