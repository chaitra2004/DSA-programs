#include<stdio.h>
struct node
{
   int data;
   struct node *next;
   struct node *prev;
};
struct node *add_pos(struct node *,int);
struct node *delete_pos(struct node *,int);
struct node *delete_data(struct node *,int);
struct node *getnode();
void display(struct node *);
main()
{
    struct node *head=NULL;
    int d,ch,pos;
    while(1)
    {
        printf("enter\n1:add at position\n2:delete at position\n3:delete all occurrence\n4:display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter the position\n");
                   scanf("%d",&pos);
                   head=add_pos(head,pos);
                  break;
            case 2:printf("enter the position\n");
                   scanf("%d",&pos);
                   head=delete_pos(head,pos);
                  break;
            case 3:printf("enter the data which is need to deleted\n");
                  scanf("%d",&d);
                  head=delete_data(head,d);
                  break;
            case 4:if(head==NULL)
                       printf("list is empty\n");
                   else
                    display(head);
                  break;
        }
    }
}
struct node *getnode()
{
    struct node *nw=(struct node*)malloc(sizeof(struct node));
    printf("enter the data\n");
    scanf("%d",&nw->data);
    nw->next=NULL;
    nw->prev=NULL;
    return nw;
}
struct node *add_pos(struct node *head,int pos)
{
    struct node *nw=getnode();
    struct node *cur=head,*p=NULL;
    int i;
    if(head==NULL)
    {
        head=nw;
        return head;
    }
    if(pos<=0)
    {
        nw->next=head;
        head->prev=nw;
        head=nw;
        return head;
    }
    for(i=0;i<pos&&cur!=NULL;i++)
    {
        p=cur;
        cur=cur->next;
    }
    nw->next=cur;
    nw->prev=p;
    p->next=nw;
    if(cur!=NULL)
        cur->prev=nw;
    return head;
}
struct node *delete_pos(struct node *head,int pos)
{
    struct node *cur=head;
    struct node *p=NULL;
    int i;
    if(head->next==NULL)
    {
        printf("deleted info %d",head->data);
        free(head);
        head=NULL;
        return head;
    }
    if(pos<=0)
    {
        printf("deleted info %d",cur->data);
        head=head->next;
        head->prev=NULL;
        free(cur);
        return head;
    }
    for(i=0;i<pos&&cur->next!=NULL;i++)
    {
        p=cur;
        cur=cur->next;
    }
    printf("deleted info %d",cur->data);
    p->next=cur->next;
    if(cur->next!=NULL)
        cur->next->prev=p;
    free(cur);
    return head;
}
struct node *delete_data(struct node *head,int d)
{
    struct node *cur=head,*p=NULL;
    if(head->next==NULL&&head->data==d)
    {
        printf("deleted info=%d\n",head->data);
        free(head);
        head=NULL;
        return head;
    }
    while(cur!=NULL)
    {
        if(cur->data==d)
        {
            if(p!=NULL)
                p->next=cur->next;
            else
                head=head->next;
            printf("deleted info=%d\n",cur->data);
            free(cur);
            return head;
        }
        p=cur;
        cur=cur->next;
    }
    if(cur->data==d)
    {
        p->next=NULL;
        printf("deleted info=%d\n",cur->data);
        free(cur);
        return head;
    }
}
void display(struct node *head)
{
    struct node *cur=head;
    while(cur!=NULL)
    {
        printf("%d\n",cur->data);
        cur=cur->next;
    }
}
