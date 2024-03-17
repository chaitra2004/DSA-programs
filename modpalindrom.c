#include<stdio.h>
 int reverse(int);
main()
{
    int n,rev;
    printf("enter the value of n\n");
    scanf("%d",&n);
    rev=reverse(n);
    if(rev==n)
        printf("palindrom\n");
    else
        printf("not palindrom\n");
}
int reverse(int n)
{
    int ld,rev=0;
    while(n!=0)
    {
        ld=n%10;
        rev=rev*10+ld;
        n=n/10;
    }
    return rev;
}
