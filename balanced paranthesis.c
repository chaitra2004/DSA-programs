#include<stdio.h>
#include<stdlib.h>
struct stack
{
    char e[30];
    int top;
};
int balpar(char []);
int isempty(struct stack *);
void push(struct stack *,char);
int pop(struct stack *);
void init(struct stack *);
main()
{
    char exp[30];
    int r;
    printf("Enter a exp\n");
    scanf("%s",exp);
    r=balpar(exp);
    if(r==0)
    {
        printf("not balanced");
    }
    else
    {
         printf("balanced");
    }
}
int balpar(char exp[])
{
    struct stack s;
    char ch;
    int i;
    init(&s);
    for(i=0;exp[i];i++)
    {
        if(exp[i]=='{'||exp[i]=='('||exp[i]=='[')
            {
                push(&s,exp[i]);
            }
            else if(exp[i]==']'||exp[i]==')'||exp[i]=='}')
            {
                ch=pop(&s);
                if(exp[i]==')'&&ch!='(')
                        {
                         return 0;
                        }
                    if(exp[i]==']'&&ch!='[')
                       {
                           return 0;
                       }
                        if(exp[i]=='}'&&ch!='{')
                       {
                           return 0;
                       }
            }
    }
    if(isempty(&s))
    {
        return 1;
    }
    return 0;
}
void init(struct stack *s)
{
    s->top=-1;
}
int isempty(struct stack *s)
{
    if(s->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *s,char c)
{
    s->top=s->top++;
    s->e[s->top]=c;
}
int pop(struct stack *s)
{
    char c;
    c=s->e[s->top];
    s->top--;
    return c;
}
