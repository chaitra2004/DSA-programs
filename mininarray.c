#include<stdio.h>
void read(int[100],int);
void disp(int[100],int);
int min(int[100],int);
main()
{
    int n,m[100],ma;
    scanf("%d",&n);
    read(m,n);
    disp(m,n);
    ma=min(m,n);
    printf("min=%d\n",ma);
}
void read(int m[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&m[i]);
    }
}

void disp(int m[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",m[i]);
    }
}
int min(int m[100],int n)
{
    int i,r;
    r=m[1];
    for(i=0;i<n;i++)
    {
        if(r>m[i])
            r=m[i];
    }
    return r;
}

