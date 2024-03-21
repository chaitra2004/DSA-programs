#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node* add_beg(struct node*);
struct node* add_end(struct node*);
void display(struct node *);
struct node* getnode();
struct node* delete_beg(struct node*);
struct node* delete_end(struct node*);
struct node* add_pos(struct node*,int);
int len(struct node*);
main()
{
    struct node *tail=NULL;
    int ch,pos,l;
    while(1)
    {
        printf("\nEnter\n1:add node at beg\n2:add node at end\n3:display\n4:delete node from beg\n5:delete node at end\n6:add node at specified pos\n7:delete node at specified pos\n8:length of the list\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:tail=add_beg(tail);
            break;
            case 2:tail=add_end(tail);
            break;
            case 3:display(tail);
            break;
            case 4:if(tail==NULL)
            printf("List is empty\n");
            else
                tail=delete_beg(tail);
            break;
            case 5:if(tail==NULL)
            printf("List is empty\n");
            else
                tail=delete_end(tail);
            break;
            case 6:printf("Enter pos\n");
            scanf("%d",&pos);
            tail=add_pos(tail,pos);
            break;
            case 8:l=len(tail);
            printf("length=%d\n",l);
            break;
        }
    }
}
struct node *getnode()
{
   struct node *nw=(struct node*)malloc(sizeof(struct node));
   printf("enter the data\n");
   scanf("%d",&nw->data);
   printf("\n");
   nw->next=nw;
   return nw;
}
struct node* add_beg(struct node *tail)
{
    struct node *newnode=getnode();
    if(tail==NULL)
    {
        tail=newnode;
        return tail;
    }
    newnode->next=tail->next;
    tail->next=newnode;
    return tail;
}
struct node* add_end(struct node *tail)
{
    struct node *newnode=getnode();
    if(tail==NULL)
    {
        tail=newnode;
        return tail;
    }
    newnode->next=tail->next;
    tail->next=newnode;
    tail=newnode;
    return tail;
}
void display(struct node *tail)
{
    struct node* cur;
    if(tail==NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    cur=tail->next;
    do
    {
        printf("%d\n",cur->data);
        cur=cur->next;
    }while(cur!=tail->next);
}
struct node *delete_beg(struct node *tail)
{
   struct node *cur;
   cur=tail->next;
   if(cur==tail)
   {
       printf("deleted info %d\n",cur->data);
       free(cur);
       tail=NULL;
       return tail;
   }
   tail->next=cur->next;
   printf("Deleted info %d\n",cur->data);
   free(cur);
   return tail;
}
struct node *delete_end(struct node *tail)
{
    struct node *cur;
   cur=tail->next;
   if(cur==tail)
   {
       printf("deleted info %d\n",cur->data);
       free(cur);
       tail=NULL;
       return tail;
   }
   while(cur->next!=tail)
   {
       cur=cur->next;
   }
   cur->next=tail->next;
   printf("Deleted info %d\n",tail->data);
   free(tail);
   tail=cur;
   return tail;
}
struct node *add_pos(struct node *tail,int pos)
{
    struct node *newnode=getnode();
    if(tail==NULL)
    {
        tail=newnode;
        return tail;
    }
    if(pos<=0)
    {
        newnode->next=tail->next;
        tail->next=newnode;
        return tail;
    }
    struct node *cur=tail->next;
    int i;
    for(i=0;i<pos-1&&cur!=tail;i++)
    {
        cur=cur->next;
    }
    newnode->next=cur->next;
    cur->next=newnode;
    if(cur==tail)
    {
        tail=newnode;
        return tail;
    }
    return tail;
}
int len(struct node *tail)
{
    int l=1;
    struct node *cur=tail->next;
    while(cur!=tail)
    {
        l++;
        cur=cur->next;
    }
    return l;
}
