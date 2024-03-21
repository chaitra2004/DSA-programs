#include<stdio.h>
struct stack
{
    int e[10];
    int top;
};
int evaprefix(char []);
int isoperand(char);
void init(struct stack *);
void push(struct stack *,char);
int pop(struct stack *);
main()
{
    int r;
    char prefix[30];
    printf("enter prefix expression\n");
    scanf("%s",prefix);
    r=evaprefix(prefix);
    printf("\nAns=%d",r);
}
int evaprefix(char prefix[30])
{
    int r,i,op1,op2,l;
    struct stack s;
    init(&s);
    l=strlen(prefix);
    for(i=l-1;i>=0;i--)
    {
        if(isoperand(prefix[i]))
        {
            push(&s,prefix[i]-48);
        }
        else
        {
            op1=pop(&s);
            op2=pop(&s);
            switch(prefix[i])
            {
                case '+':r=op1+op2;
                       push(&s,r);
                       break;
                case '-':r=op1-op2;
                       push(&s,r);
                       break;
                case '*':r=op1*op2;
                       push(&s,r);
                       break;
                case '/':r=op1/op2;
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
    if (ch>='0'&&ch<='9')
    {
        return 1;
    }
    return 0;
}
