#include<stdio.h>
main()
{
    FILE *input,*output;
    int i;
    int a[100];
    input=fopen("input.txt","r");
    output=fopen("output.txt","w");
     if(input==NULL)
     {
         perror("Error:");
         return 1;
     }
    while(!feof(input))
    {
        fscanf(input,"%d",&a[i]);
        printf("\n%d\n",a[i]);
        i++;
    }
    fclose(output);

    return 0;
}
