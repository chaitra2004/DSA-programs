#include<stdio.h>
main()
{
    char s[20];
    int x;
    printf("enter string\n");
    gets(s);
    x=strlen(s);
    printf("string length=%d",x);
}
