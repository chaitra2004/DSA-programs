#include<stdio.h>
int max(int);
main()
{
    int n,m;
    printf("enter n\n");
    scanf("%d",&n);
    m=max(n);
    printf("max digit=%d",m);

}
int max(int n)
{
    int m,ld;
    m=n%10;
    while(n!=0)
    {
        ld=n%10;
        if(ld>m)
            m=ld;
        n=n/10;
    }
    return m;
}

