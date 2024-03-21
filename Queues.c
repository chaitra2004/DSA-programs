#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int e[5];
    char name[20];
    int front;
    int rear;
};
void initQ(struct queue *q);
void enqueue(struct queue *q,int);
int isFull(struct queue *q);
int dequeue(struct queue *q);
int isEmpty(struct queue *q);
int size(struct queue *q);
int getFront(struct queue *q);
void display(struct queue *q);
main()
{
    struct queue q;
    int ch,data,s;
    initQ(&q);
    while(1)
    {
        printf("1:Enqueue\n");
        printf("2:Dequeue\n");
        printf("3:Size\n");
        printf("4:Get Front\n");
        printf("5:display\n");
        printf("6:Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the value\n");
                            scanf("%d",&data);
                            if(isFull(&q))
                            {
                                printf("queue is full\n");
                            }
                            else
                            {
                                enqueue(&q,data);
                            }
                            break;
            case 2:if(isEmpty(&q))
                            {
                                    printf("q is empty\n");
                            }
                            else
                            {
                                data=dequeue(&q);
                                printf("%d\n",data);
                            }
                            break;
            case 3:
                                if(isEmpty(&q))
                                {
                                    s=0;
                                }
                                else
                                    s=size(&q);
                                printf("Size=%d\n",s);
                             break;
            case 4: if(isEmpty(&q))
                                {
                                        printf("Q is Empty\n");
                                }
                                else
                                {
                                    data=getFront(&q);
                                    printf("Front value :%d\n",data);
                                }
                                break;
            case 5:
                    if(isEmpty(&q))
                    {
                        printf("Q is empty\n");
                    }
                    else
                        display(&q);
                        break;
                case 6:exit(0);
        }
    }
}
void initQ(struct queue *q)
{
    q->front=0;
    q->rear=-1;
}
void enqueue(struct queue *q,int data)
{
    q->rear++;
    q->e[q->rear]=data;
}
int isFull(struct queue *q)
{
    if(q->rear==5-1)
    {
        return 1;
    }
    return 0;
}
int dequeue(struct queue *q)
{
    int d;
    d=q->e[q->front];
    q->front++;
    return d;
}
int isEmpty(struct queue *q)
{
    if(q->rear < q->front)
    {
        return 1;
    }
    return 0;
}
int size(struct queue *q)
{
    return ((q->rear)-(q->front)+1);
}
int getFront(struct queue *q)
{
    return q->e[q->front];
}
void display(struct queue *q)
{
    int i;
    for(i=q->front;i<=q->rear;i++)
    {
        printf("%d\n",q->e[i]);
    }
}
