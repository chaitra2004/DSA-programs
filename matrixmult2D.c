#include<stdio.h>
void read(int [][100],int ,int);
void display(int [][100],int,int);
void mul(int [][100],int [][100],int [][100],int,int,int,int);
main()
{
    int a[100][100],b[100][100],p[100][100],r1,c1,r2,c2;
    printf("enter r1 and c1 for matrix 1\n");
    scanf("%d%d",&r1,&c1);
    printf("enter r2 and c2 for matrix 2\n");
    scanf("%d%d",&r2,&c2);
    printf("enter elements of matrix 1\n");
    read(a,r1,c1);
    printf("enter elements of matrix 2\n");
    read(b,r2,c2);
    display(a,r1,c1);
    printf("\n");
    display(b,r2,c2);
    mul(a,b,p,r1,c1,r2,c2);
    printf("product=\n");
    display(p,r1,c2);
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
void mul(int a[100][100],int b[100][100],int p[100][100],int r1,int c1,int r2,int c2)
{
    int i,j,k;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            for(k=0;k<c1;k++)
            {
                p[i][j]=p[i][j]+a[i][k]*b[k][j];
            }
        }
    }
}
