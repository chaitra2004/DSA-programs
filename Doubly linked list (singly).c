#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node * getnode();
struct node * add_beg(struct node *);
struct node * add_end(struct node *);
void display(struct node *);
struct node * delete_beg(struct node *);
struct node * delete_end(struct node *);
struct node * add_pos(struct node *,int);
struct node * delete_pos(struct node *,int);
struct node * merge(struct node *,struct node *);
struct node * delete_data(struct node *,int);
struct node * rev(struct node *);
main()
{
    struct node *head=NULL,*head1=NULL;
    int ch,pos,d;
    char c;
    while(1)
    {
        printf("Enter\n1:To add at the beg\n");
        printf("2:To add at the end\n");
        printf("3:To display\n");
        printf("4:To delete at the beg\n");
        printf("5:To delete at the end\n");
        printf("6:To add at the pos\n");
        printf("7:To delete at the pos\n");
        printf("8:To create 2 lists\n");
        printf("9:To merge\n");
        printf("10:TO delete by data\n");
        printf("11:To reverse\n");
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
                         head = delete_beg(head);
                     }
                     else
                     {
                         printf("List is empty\n");
                     }
                     break;
             case 5: if(head!=NULL)
                     {
                         head = delete_end(head);
                     }
                     else
                     {
                         printf("List is empty\n");
                     }
                     break;
            case 6:  printf("Enter the pos\n");
                     scanf("%d",&pos);
                     head = add_pos(head,pos);
                     break;
            case 7:  if(head!=NULL)
                     {
                         printf("Enter the pos\n");
                         scanf("%d",&pos);
                         head = delete_pos(head,pos);
                     }
                     else
                     {
                         printf("List is empty\n");
                     }
                     break;
             case 8: printf("Enter o to add in list one\n");
                       scanf("%*c%c",&c);
                       if(c=='o')
                       {
                           head=add_beg(head);
                       }
                       else
                       {
                           head1=add_beg(head1);
                       }
                       break;
               case 9: head=merge(head,head1);
                         break;
               case 10:  if(head!=NULL)
                        {
                         printf("Enter the data\n");
                         scanf("%d",&d);
                         head = delete_data(head,d);
                         }
                         else
                        {
                         printf("List is empty\n");
                        }
                        break;
                 case 11: head=rev(head);
                           break;
        }
    }
}
struct node * getnode()
{
   struct node *newnode;
   newnode= (struct node *)malloc(sizeof(struct node));
   printf("Enter the data\n");
   scanf("%d",&newnode->data);
   newnode->next=NULL;
   newnode->prev=NULL;
   return newnode;
}
struct node * add_beg(struct node *head)
{
   struct node *newnode=getnode();
   if(head==NULL)
   {
       head=newnode;
       return newnode;
   }
   newnode->next=head;
   head->prev=newnode;
   head=newnode;
   return head;
}
struct node * add_end(struct node *head)
{
   struct node *newnode=getnode();
   struct node *cur=head;
   if(head==NULL)
   {
       head=newnode;
       return head;
   }
   while(cur->next!=NULL)
   {
       cur=cur->next;
   }
   cur->next=newnode;
   newnode->prev=cur;
   return head;
}
void display(struct node *head)
{
    struct node *cur = head;
    while(cur!=NULL)
    {
        printf("Data=%d\n",cur->data);
        cur=cur->next;
    }
}
struct node * delete_beg(struct node *head)
{
   struct node *cur=head;
   if(head->next==NULL)
   {
       printf("Deleted information\nData=%d\n",head->data);
       free(head);
       head=NULL;
       return head;
   }
   head=head->next;
   head->prev=NULL;
   printf("Deleted information\nData=%d\n",cur->data);
   free(cur);
   return head;
}
struct node * delete_end(struct node *head)
{
   struct node *cur=head;
   struct node *p=NULL;
   if(head->next==NULL)
   {
       printf("Deleted information\nData=%d\n",head->data);
       free(head);
       head=NULL;
       return head;
   }
   while(cur->next!=NULL)
   {
       p=cur;
       cur=cur->next;
   }
    printf("Deleted information\nData=%d\n",cur->data);
    p->next=NULL;
    free(cur);
    return head;
}
struct node * add_pos(struct node *head,int pos)
{
    int i;
   struct node *newnode =getnode();
   if(head==NULL)
   {
       head=newnode;
       return head;
   }
   if(pos<=0)
   {
       newnode->next=head;
       head->prev=newnode;
       head=newnode;
       return newnode;
   }
   struct node *cur=head,*p=NULL;
   for(i=0;i<pos-1&&cur->next!=NULL;i++)
   {
       cur=cur->next;
       p=cur->next;
   }
    newnode->next=cur->next;
    cur->next=newnode;
    newnode->prev=cur;
    p->prev=newnode;
    return head;
}
struct node * delete_pos(struct node *head, int pos)
{
    int i;
    struct node *cur=head;
    struct node *p=NULL,*t=NULL;
    if(head->next==NULL)
    {
        printf("Deleted Information\nData=%d\n",head->data);
        free(head);
        head=NULL;
        return head;
    }
    if(pos<=0)
    {
       head=head->next;
       head->prev=NULL;
        printf("Deleted Information\nData=%d\n",cur->data);
        free(cur);
        return head;
    }
    for(i=0;i<pos-1&&cur->next!=NULL;i++)
    {
        p=cur;
        cur=cur->next;
    }
    p->next=cur->next;
    if(cur->next!=NULL)
    {
        cur->next->prev=p;
    }

}
struct node *merge(struct node *head,struct node *head1)
{
   struct node *cur=head;
   while(cur->next!=NULL)
   {
       cur=cur->next;
   }
   cur->next=head1;
   head1->prev=cur;
   return head;
}
struct node *delete_data(struct node *head,int d)
{
    struct node *cur=head;
    struct node *p=NULL,*t=NULL;
   if(head->next==NULL&&head->data==d)
   {
         printf("Deleted Information\nData=%d\n",head->data);
         free(head);
         head=NULL;
         return head;
   }
   while(cur!=NULL)
    {
        if(cur->data==d)
        {
            t=cur;
            if(p!=NULL)
            {
                p->next=cur->next;
            }
            if(cur->next!=NULL)
            {
                cur->next->prev=p;
            }
            p=cur;
            cur=cur->next;
            printf("Deleted info : %d\n",t->data);
            free(t);
        }
        else
        {
            p=cur;
            cur=cur->next;
        }
    }
    return head;
}
struct node *rev(struct node *head)
{
    struct node *p=head,*cur=head,*t=NULL,*n=cur->next;
    while(cur!=NULL)
    {
       t=cur->next;
       cur->next=cur->prev;
       cur->prev=t;
       head=cur;
       cur=n;
       if(n!=NULL)
          n=n->next;
    }
    return head;
}


