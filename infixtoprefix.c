#include<stdio.h>
#include<stdlib.h>
struct stack
{
    char e[30];
    int top;
};
void convInfixToPrefix(char []);
void isitstack(struct stack *);
void push(struct stack*,char);
char pop(struct stack*);
char peek(struct stack *);
int isEmpty(struct stack*);
int isOperand(char);
int isOperator(char);
int pre(char);
main()
{
    char infix[30];
    printf("Enter a infix exp\n");
    scanf("%s",infix);
    convInfixToPrefix(infix);
}
void convInfixToPrefix(char infix[30])
{
    struct stack s;
    isitstack(&s);
    int i,j=0,l,k;
    char temp[30];
    char prefix[30];
    l=strlen(infix);
    for(i=l-1;i>=0;i--)
    {
        if(isOperand(infix[i]))
        {
            prefix[j]=infix[i];
            j++;
        }
        else if(isOperator(infix[i]))
        {
            if(isEmpty(&s))
            {
                push(&s,infix[i]);
            }
            else if(pre(infix[i])>=pre(peek(&s)))
            {
                push(&s,infix[i]);
            }
            else
            {
                while(!isEmpty(&s)&&pre(infix[i])<pre(peek(&s))&&peek(&s)!=')')
                      {
                          prefix[j]=pop(&s);
                            j++;
                      }

                push(&s,infix[i]);
            }
        }
        else if(infix[i]==')')
        {
            push(&s,infix[i]);
        }
        else if(infix[i]=='(')
        {
            while(!isEmpty(&s)&&peek(&s)!=')')
            {
                prefix[j]=pop(&s);
                j++;
            }
            pop(&s);
        }
    }
    while(!isEmpty(&s))
    {
        prefix[j]=pop(&s);
        j++;
    }
    prefix[j]='\0';
    j=0;
    while(prefix[j])
    {
        push(&s,prefix[j]);
        j++;
    }
    k=0;
    while(!isEmpty(&s))
    {
        temp[k]=pop(&s);
        k++;
    }
    temp[k]='\0';
    printf("Prefix= %s\n",temp);
}
void isitstack(struct stack *s)
{
    s->top=-1;
}
void push(struct stack *s,char ele)
{
    s->top++;
    s->e[s->top]=ele;
}
char pop(struct stack *s)
{
    char ele;
    ele=s->e[s->top];
    s->top--;
    return ele;
}
char peek(struct stack *s)
{
    char ele;
    ele=s->e[s->top];
    return ele;
}
int isEmpty(struct stack *s)
{
    if(s->top==-1)
    {
        return 1;
    }
    else
        return 0;
}
int isOperand(char ch)
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
int isOperator(char  ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='$')
    {
        return 1;
    }
    return 0;
}
int pre(char ch)
{
    if(ch=='+'||ch =='-')
    {
        return 1;
    }
    else if(ch=='*'||ch=='/')
            return 2;
    else if(ch=='$')
        return 3;
    return -1;
}
