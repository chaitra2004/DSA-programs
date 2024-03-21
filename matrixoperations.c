#include<stdio.h>
void read(int[100][100],int,int);
void display(int [100][100],int,int);
void sum(int[100][100],int[100][100],int,int);
void subb(int[100][100],int[100][100],int,int);
void multi(int[100][100],int[100][100],int,int,int,int);
void transpose(int[100][100],int,int);
main()
{
    FILE *ptr;
    if(ptr==NULL)
    {
        printf("Error in the file opening\n");
        return 1;
    }
    int a[100][100],op;
    int b[100][100],r1,c1,r2,c2;
    printf("Enter thr values of r1 and c1\n");
    scanf("%d",&r1);
    scanf("%d",&c1);
    printf("Enter thr values of r2 and c2\n");
    scanf("%d",&r2);
    scanf("%d",&c2);
    read(a,r1,c1);
    read(b,r2,c2);
    display(a,r1,c1);
    display(b,r2,c2);
    printf("Enter\n1.To add matrices\n2.To subtract two matrices\n3.To multiply\n4.To find transpose\n");
    scanf("%d",&op);
    if(op==1)
    {
        sum(a,b,r1,c1);
    }
    else if(op==2)
    {
        subb(a,b,r1,c1);
    }
    else if(op==3)
    {
        multi(a,b,r1,c1,r2,c2);
    }
    else if(op==4)
    {
        transpose(a,r1,c1);
    }
    fclose(ptr);
}
void read(int a[100][100],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }
}
void display(int a[100][100],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void sum(int a[100][100],int b[100][100],int r,int c)
{
    int i,j;
    int d[100][100];
    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
        {
            d[j][i]=a[j][i]+b[j][i];
        }
        printf("\n");
    }
   FILE *output = fopen("matrix.txt", "w");
    if (output == NULL)
    {
        printf("Error in opening the file:\n");
        return 1;
    }
    print_array(output, d, r,c);
    fclose(output);
    return 0;
}
void subb(int a[100][100],int b[100][100],int r,int c)
{
    int i,j;
    int d[100][100];
    for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
        {
            d[j][i]=a[j][i]-b[j][i];
        }
        printf("\n");
    }
    FILE *output = fopen("matrix.txt", "w");
    if (output == NULL)
    {
        printf("Error in opening the file:\n");

    }
    print_array(output, d, r,c);
    fclose(output);

}
void multi(int a[100][100],int b[100][100],int r1,int c1,int r2,int c2)
{
    int i,j,k;
    int c[100][100];
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            for(k=0;k<c1;k++)
            {
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }
   FILE *output = fopen("matrix.txt", "w");
    if (output == NULL)
    {
        printf("Error in opening the file:\n");
        return 1;
    }
    print_array(output, c, r1, c2 );
    fclose(output);
    return 0;
}
void transpose(int a[100][100],int r,int c)
{
    int i,j,t[100][100];
    for(i=0;i<r;i++)
    {
       for(j=0;j<c;j++)
       {
          t[i][j]=a[j][i];
       }
    }
    FILE *output = fopen("matrix.txt", "w");
    if (output == NULL)
    {
        printf("Error in opening the file:\n");
        return 1;
    }
    print_array(output, t, r,c);
    fclose(output);
    return 0;
}
void print_array(FILE *ptr, int a[100][100], int r,int c)
 {
    int i,j;
    for (i = 0; i < r; i++)
    {
        for(j=0;j<c;j++)
        {
            fprintf(ptr, "%d\t", a[i][j]);
        }
        fprintf(ptr,"\n");
    }
    printf("\nThe result is stored in matrix file\n");
}
