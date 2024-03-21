#include<stdio.h>
 int reverse(int);
main()
{
    FILE *ptr;
    int n,rev;
     ptr=fopen("palindrome.txt","w");
    if(ptr==NULL)
    {
        printf("Error in the file opening\n");
        return 1;
    }
    printf("enter the value of n\n");
    scanf("%d",&n);
    rev=reverse(n);
    if(rev==n)
        fprintf(ptr," %d is palindrome\n",n);
    else
        fprintf(ptr,"%d is not a palindrome\n",n);
    fclose(ptr);
     printf("The result is stored in palindrome file\n");
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

