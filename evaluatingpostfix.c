#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int e[30];
    int top;
};
int evapostfix(char []);
int isoperand(char);
void init(struct stack *);
void push(struct stack *,char);
int pop(struct stack *);
main()
{
    char postfix[30];
    int r;
    printf("Enter the postfix\n");
    scanf("%s",postfix);
    r=evapostfix(postfix);
    printf("\n%d\n",r);
}
int evapostfix(char postfix[30])
{
    int i,r,op1,op2;
    struct stack s;
    init(&s);
    for(i=0;postfix[i];i++)
    {
        if(isoperand(postfix[i]))
        {
            push(&s,postfix[i]-48);
        }
        else
        {
            op2=pop(&s);
            op1=pop(&s);
            switch(postfix[i])
            {
                case'+':r=op1+op2;
                        push(&s,r);
                        break;
                case'-':r=op1-op2;
                        push(&s,r);
                        break;
                 case'*':r=op1*op2;
                        push(&s,r);
                        break;
                 case'/':r=op1/op2;
                        push(&s,r);
                        break;
                 case'$':r=pow(op1,op2);
                        push(&s,r);
                        break;

            }
        }
    }
    return(pop(&s));
}
void init(struct stack *s)
{
	s->top=-1;
}
void push(struct stack *s,char ele)
{
    s->top++;
    s->e[s->top]=ele;
}
int pop(struct stack *s)
{
    int ele;
    ele=s->e[s->top];
    s->top--;
    return ele;
}
int isoperand(char ch)
{
    if(ch>='A'&&ch<='Z')
    {
        return 1;
    }
    else if(ch>='a'&&ch<='z')
    {
        return 1;
    }
    else if (ch>='0'&&ch<='9')
    {
        return 1;
    }
    return 0;
}
