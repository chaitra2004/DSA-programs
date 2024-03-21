#include<stdio.h>
void read(int [],int);
void display(int [],int);
int linearSearch(int [],int,int);
int main()
{
    FILE *ptr;
    ptr=fopen("linearsearch.txt","w");
    if(ptr==NULL)
    {
        printf("Error in the file opening\n");
        return 1;
    }
    int a[100];
    int n,r,k;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    read(a,n);
    display(a,n);
    printf("Enter the number to be searched\n");
    scanf("%d",&k);

     if (r == -1)
     {
       fprintf(ptr,"Element is not present in array\n");
     }
    else
    {
      fprintf(ptr,"Element is present in array\n");
    }
    fclose(ptr);
    printf("The result is saved in linearsearch file\n");
}
void read(int a[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void display(int a[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
int linearSearch(int a[100],int n,int k)
 {
     int i,l1;
     for(i=0;i<n;i++)
     {
        if(a[i]==k)
        {
            return 1;
        }
     }
    return -1;
}
