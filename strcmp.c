#include<stdio.h>
main()
{
    char s1[20],s2[20];
    int x;
    printf("enter 2 strings\n");
    gets(s1);
    gets(s2);
    x=strcmp(s1,s2);
    if(x==0)
        printf("s1 and s2 are same\n");
    else
        printf("s1 and s2 are not same\n");
}
