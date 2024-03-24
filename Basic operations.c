#include<stdio.h>
struct stack
{
	int e[5];
	int top;
};
void init(struct stack *);
int isFull(struct stack *);
int isEmpty(struct stack *);
void push(struct stack *,int ele);
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
		printf("\n1:PUSH");
		printf("\n2:POP");
		printf("\n3:PEAK");
		printf("\n4:DISPLAY");
		printf("\n5:SIZE");
		printf("\n6:EXIT\n");
		scanf("%d",&ch);
	switch(ch)
	{
		case 1:if(isFull(&s))
                        {
                                printf("Stack is full\n");
                        }
                        else
                        {
                        printf("Enter a element to push\n");
                        scanf("%d",&ele);
                        push(&s,ele);
                        }
                        break;
            case 2: if(isEmpty(&s))
                  {
                    printf("Stack is Empty\n");
                  }
                  else
                  {
                    ele=pop(&s);
                    printf("\npop=%d\n",ele);
                  }
                    break;
            case 3:if(isEmpty(&s))
                            {
                                    printf("Stack is empty\n");
                            }
                            else
                            {
                                ele=peak(&s);
                                printf("Peak element is %d",ele);
                            }
                            break;
                case 4:display(&s);
                                break;
                case 5:si=size(&s);
                                printf("Size=%d\n",si);
                                break;
	       }
	}
}
void init(struct stack *s)
{
	s->top=-1;
}
void push(struct stack *s,int ele)
{
    s->top++;
    s->e[s->top]=ele;
}
int isFull(struct stack *s)
{
    if(s->top==4)
    {
        return 1;
    }
    else
        return 0;
}
int pop(struct stack *s)
{
    int ele;
    ele=s->e[s->top];
    s->top--;
    return ele;
}
int isEmpty(struct stack *s)
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
    int si;
    si=s->top+1;
    return si;
}
