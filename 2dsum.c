#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void read(char [100][100],int,int);
void win(char [100][100],int,int);
int main()
{
   char a[100][100];
    int r,c;
    scanf("%d%d",&r,&c);
    if(r<=0||c<=0)
    {
        printf("Invalid players and matches");
    }
    else
    {
        read(a,r,c);
        win(a,r,c);
    }
}
void read(char a[100][100],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%c%*c",&a[i][j]);
        }
    }
}
void win(char a[100][100],int r,int c)
{
    int i,j,w;
    for(i=0;i<r;i++)
    {
         w=0;
        for(j=0;j<c;j++)
        {
            if(a[i][j]=='W')
           {
              w++;
           }
        }
        printf("Player %d won %d matches\n",i+1,w+1);
    }
}
