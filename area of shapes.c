#include<stdio.h>
float cir(int);
float tri(int,int);
float rect(int,int);
main()
{
    FILE *ptr;
    int r,b,h,w,l,s;
    float c,t,re;
    ptr=fopen("area of shapes.txt","w");
    if(ptr==NULL)
    {
        printf("Error in the file opening\n");
        return 1;
    }
    printf("Enter the shape 1.Circle 2.Triangle 3.Rectangle\n");
    scanf("%d",&s);
    if(s==1)
    {
        printf("enter the  radius\n");
        scanf("%d",&r);
        c=cir(r);
        fprintf(ptr,"area of circle with radius %d is %f",r,c);
    }
    else if(s==2)
    {
        printf("enter the base and height of triangle\n");
        scanf("%d%d",&b,&h);
        t=tri(b,h);
        fprintf(ptr,"area of triangle with base %d and height %d is %f",b,h,t);
    }
    else if(s==3)
    {
        printf("enter the width and length of rectangle\n");
        scanf("%d%d",&w,&l);
        re=rect(w,l);
        fprintf(ptr,"area of rectangle with width %d and length %d is %f",w,l,re);
    }
    fclose(ptr);
    printf("The result is stored in area of shapes file\n");
}
float cir(int r)
{
    float a;
    a=3.14*r*r;
    return a;
}
float tri(int b,int h)
{
    float a;
    a=0.5*b*h;
    return a;
}
float rect(int w,int l)
{
    float a;
    a=l*w;
    return a;
}

