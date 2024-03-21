#include<stdio.h>
 #include<string.h>
 void read(char[]);
 void display(char[]);
 void merge(char[],char[]);
 int str_cmp(char [],char[]);
 void copying(char []);
 main()
 {
    FILE *ptr;
    int res;
    ptr=fopen("strings.txt","w");
    if(ptr==NULL)
    {
        printf("Error in the file opening\n");
        return 1;
    }
     char s1[100],s2[100];
     int x,op;
     printf("Enter the first string\n");
     read(s1);
     printf("Enter the second string\n");
     read(s2);
     display(s1);
     display(s2);
     printf("\nEnter\n1.To concatenation\n2.copying\n3.Compare\n");
     scanf("%d",&op);
     if(op==1)
     {
         merge(s1,s2);
     }
     else if(op==2)
     {
          copying(s1);
     }
     else if(op==3)
     {
        x=str_cmp(s1,s2);
        if(x==0)
        {
          fprintf(ptr,"s1 and s2 are same\n");
        }
        else
        {
          fprintf(ptr,"s1 and s2 are not same\n");
        }
     }
     fclose(ptr);
    printf("The result is saved in strings file\n");

}
void read(char s1[100])
{
    gets(s1);
}
void display(char s1[100])
{
    puts(s1);
}
int str_cmp(char s1[100],char s2[100])
{
    int l1,l2,i=0;
    l1=strlen(s1);
    l2=strlen(s2);
    if(l1==l2)
    {
        while(s1[i]!='\0'||s2[i]!='\0')
        {
            if(s1[i]!=s2[i])
            {
                return 1;
            }
            i++;
        }
        return 0;
    }
    else
    {
        return 1;
    }
}
void merge(char s1[100],char s2[100])
{
    FILE *ptr;
    int res;
    ptr=fopen("strings.txt","w");
    int i,j,l1,l2,l;
    l1=strlen(s1);
    l2=strlen(s2);
    l=l1+l2;
    for(i=0;s1[i]!='\0';i++)
    {
        for(j=0;s2[j]!='\0';j++,i++)
        {
            s1[i]=s2[j];
        }
    }
    s1[i]='\0';
    for(i=0;i<l;i++)
    {
        fputs(ptr,s1);
    }
    fclose(ptr);
    printf("The result is saved in strings file\n");
}
void copying(char s1[100])
{
    FILE *ptr;
    int res;
    ptr=fopen("strings.txt","w");
    int i;
    char s2[100];
    for (i = 0; s1[i] != '\0'; i++)
    {
       s2[i] = s1[i];
    }
    for(i=0;s2[i]!='\0';i++)
    {
        fputs(ptr,s2);
    }
    fclose(ptr);
    printf("The result is saved in strings file\n");
}
