#include<stdio.h>
void read(int[],int);
void display(int[],int);
int max(int[],int);
int min(int[],int);
int sum(int[],int);
int avg(int[],int);
main()
{
    FILE *ptr;
    int res;
    ptr=fopen("array operations.txt","w");
    if(ptr==NULL)
    {
        printf("Error in the file opening\n");
        return 1;
    }
    int n,op;
    int m[100],maxm,minm,s,a;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    read(m,n);
    display(m,n);
    printf("\nEnter\n1.To find largest element\n2.To find smallest element\n3.To find sum of array\n4.To find average of the array\n");
    scanf("%d",&op);
    if(op==1)
    {
      maxm=max(m,n);
      fprintf(ptr,"\nMAX=%d\n",maxm);
    }
    else if(op==2)
    {
      minm=min(m,n);
      fprintf(ptr,"MIN=%d\n",minm);
    }
    else if(op==3)
    {
        s=sum(m,n);
        fprintf(ptr,"SUM=%d\n",s);
    }
    else if(op==4)
    {
        a=avg(m,n);
        fprintf(ptr,"Average=%d\n",a);
    }
   printf("The result is saved in array file\n");
}
void read(int m[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&m[i]);
    }
}
void display(int m[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",m[i]);
    }
}
int max(int m[100],int n)
{
    int i;
    int r;
    r=m[1];
    for(i=0;i<n;i++)
    {
        if(r<m[i])
        {
            r=m[i];
        }
    }
    return r;
}
int min(int m[100],int n)
{
    int i;
    int r;
    r=m[1];
    for(i=0;i<n;i++)
    {
        if(r>m[i])
        {
            r=m[i];
        }
    }
    return r;
}
int sum(int m[100],int n)
{
    int s=0,i;
    for(i=0;i<n;i++)
    {
        s=s+m[i];
    }
    return s;
}
int avg(int m[100],int n)
{
    int a=0,s=0,i;
    for(i=0;i<n;i++)
    {
        s=s+m[i];
    }
    a=s/2;
    return a;
}
