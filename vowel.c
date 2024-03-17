#include<stdio.h>
main()
{
    char ch;
    printf("enter a character\n");
    scanf("%c",&ch);
    switch(ch)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':printf("vowel");
        break;
        default:printf("not a vowel");
    }
}
