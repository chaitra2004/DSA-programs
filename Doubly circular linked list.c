#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node * getnode();
struct node * add_beg(struct node*);
struct node * add_end(struct node*);
void display(struct node *);
struct node * delete_beg(struct node *);
struct node * delete_end(struct node *);
main()
{
    int ch;
    struct node *head=NULL;
    while(1)
    {
        printf("Enter\n1:To add at beg\n");
        printf("2:To add at end\n");
        printf("3:To display\n");
        printf("4:To delete from beg\n");
        printf("5:To delete from end\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head = add_beg(head);
                      break;
            case 2: head = add_end(head);
                      break;
            case 3: display(head);
                      break;
            case 4: if(head!=NULL)
                      {
                          head=delete_beg(head);
                      }
                      else
                      {
                          printf("List is empty\n");
                      }
                      break;
            case 5:   if(head!=NULL)
                      {
                          head=delete_end(head);
                      }
                      else
                      {
                          printf("List is empty\n");
                      }
                      break;
        }
    }
}
struct node * getnode()
{
   struct node *newnode;
   newnode=(struct node *)malloc(sizeof(struct node));
   printf("Enter the data\n");
   scanf("%d",&newnode->data);
   newnode->next=newnode;
   newnode->prev=newnode;
   return newnode;
}
struct node * add_beg(struct node *head)
{
   struct node *newnode=getnode();
   if(head==NULL)
   {
       head=newnode;
       return head;
   }
   newnode->next=head;
   head->prev=newnode;
   newnode->prev=head->prev;
   newnode->prev->next=newnode;
   head=newnode;
   return head;
}
struct node * add_end(struct node *head)
{
    struct node *newnode=getnode();
        if(head==NULL)
        {
            head=newnode;
            return head;
        }
        newnode->next=head;
        newnode->prev=head->prev;
        newnode->prev->next=newnode;
        head->prev=newnode;
        return head;
}
void display(struct node *head)
{
    struct node *cur=head;
    do
    {
        printf("Data=%d\n",cur->data);
        cur=cur->next;
    }while(cur!=head);
}
struct node * delete_beg(struct node *head)
{
    if(head->next==NULL)
    {
        printf("Deleted information = %d\n",head->data);
        free(head);
        head=NULL;
        return head;
    }
    struct node *cur=head;
    head=head->next;
    head->prev=cur->prev;
    cur->next->prev=head;
    printf("Deleted information = %d\n",cur->data);
    free(cur);
    return head;
}
struct node * delete_end(struct node *head)
{

}
