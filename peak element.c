#include<stdio.h>
#include<string.h>
struct stack
{
    int e[5];
    int top;
};
void init(struct stack *);
int isfull(struct stack *);
int isempty(struct stack *);
void push(struct stack *,int);
int pop(struct stack *);
int peak(struct stack *);
void display(struct stack *);
int size(struct stack *);
main()
{
    struct stack s;
    int ch,ele,si;
    init(&s);
    while(1)
    {
        printf("1:PUSH\n");
        printf("2:POP\n");
        printf("3:PEAK\n");
        printf("4:DISPLAY\n");
        printf("5:SIZE\n\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if(isfull(&s))
                     {
                         printf("Stack is full\n");
                     }
                     else
                     {
                         printf("Enter a number to push\n");
                         scanf("%d",&ele);
                         push(&s,ele);
                     }
                     break;
             case 2: if(isempty(&s))
                     {
                         printf("Stack is empty\n");
                     }
                     else
                     {
                         ele=pop(&s);
                         printf("Poped element=%d\n",ele);
                     }
                     break;
              case 3: if(isempty(&s))
                      {
                          printf("Stack is empty\n");
                      }
                      else
                      {
                          ele=peak(&s);
                          printf("Peak element=%d\n",ele);
                      }
                      break;
               case 4: display(&s);
                       break;
               case 5: if(isempty(&s))
                      {
                          printf("Stack is empty\n");
                      }
                      else
                      {
                          si=size(&s);
                          printf("SIZE=%d\n",si);
                      }
                      break;
        }
    }
}
void init(struct stack *s)
{
    s->top=-1;
}
int isfull(struct stack *s)
{
    if(s->top==4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
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
void push(struct stack *s,int ele)
{
    s->top=s->top++;
    s->e[s->top]=ele;
}
int pop(struct stack *s)
{
    int ele;
    ele=s->e[s->top];
    s->top--;
    return ele;
}
int peak(struct stack *s)
{
    int ele;
    ele=s->e[s->top];
    return ele;
}
void display(struct stack *s)
{
    int i;
    for(i=s->top;i>=0;i--)
    {
        printf("%d\n",s->e[i]);
    }
}
int size(struct stack *s)
{
    int ele;
    ele=s->top+1;
    return ele;
}
