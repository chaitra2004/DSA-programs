#include<stdio.h>
void ind_A(float);
void ind_B(float);
void ind_C(float);
main()
{
    float avg;
    char g;
    printf("enter the grade\n");
    scanf("%c",&g);
    switch(g)
    {
        case 'A':ind_A(avg);
        break;
        case 'B':ind_B(avg);
        break;
        case 'C':ind_C(avg);
        break;
    }
}
void ind_A(float avg)
{
    printf("enter the average\n");
    scanf("%f",&avg);
    if(avg<=30)
        printf("20 lkh\n");
    else if(avg<=35)
        printf("50 lkh\n");
    else if(avg<=40)
        printf("1 crore\n");
    else if(avg<=45)
        printf("2 crore\n");
    else
        printf("5 crore\n");
}
void ind_B(float avg)
{
    printf("enter the average\n");
    scanf("%f",&avg);
       if(avg<=30)
        printf("20 lkh\n");
    else if(avg<=35)
        printf("50 lkh\n");
    else if(avg<=40)
        printf("1 crore\n");
    else if(avg<=45)
        printf("2 crore\n");
    else
        printf("5 crore\n;");
}
void ind_C(float avg)
{
    printf("enter the average\n");
    scanf("%f",&avg);
    if(avg<=30)
        printf("5 lkh\n");
    else if(avg<=35)
        printf("30 lkh\n");
    else if(avg<=40)
        printf("60 lkh\n");
    else if(avg<=45)
        printf("80 lkh\n");
    else
        printf("1 crore\n;");
}

