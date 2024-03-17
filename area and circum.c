#include<stdio.h>
void area(float);
main()
{
    float r,area;
    printf("enter value of r\n");
    scanf("%f",&r);
    area(r);
}
void area(float r)
{
    float area,cm;
    area=3.148*r*r;
    cm=2*3.14*r;
    printf("area=%f\ncm=%f",area,cm);
}
