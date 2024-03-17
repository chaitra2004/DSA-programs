#include<stdio.h>
int isarmstrong(int);
int main()
{
    int n,a;
    printf("enter n\n");
    scanf("%d",&n);
    a=isarmstrong(n);
    if(a==n)
        printf("is armstrong");
    else
        printf("not armstrong");
}
int isarmstrong (int n)
{
        int ld,sum=0;
        while(n)
        {
            ld=n%10;
            sum=sum+ld*ld*ld;
            n=n/10;

        }
        return sum;
}


