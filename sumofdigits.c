#include<stdio.h>
int sum(int);
main()
{
    FILE *ptr;
    ptr=fopen("sumofdigits.txt","w");
    int n,s;
    if(ptr==NULL)
    {
        printf("Error in the file opening\n");
        return 1;
    }
    printf("Enter the number\n");
    scanf("%d",&n);
    if(n>0)
    s=sum(n);
    fprintf(ptr,"SUM of %d = %d",n,s);
    fclose(ptr);
    printf("The reult is stored in sumofdigits file\n");
}
int sum(int n)
{
    int ld,s=0;
    while(n!=0)
    {
        ld=n%10;
        s=s+ld;
        n=n/10;
    }
    return s;
}
