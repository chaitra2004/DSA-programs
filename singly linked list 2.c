#include<stdio.h>
struct node
{
    char name[20];
    int data;
    struct node *next;
};
struct node * getnode();
struct node * add_beg(struct node *);
struct node * add_end(struct node *);
struct node * add_pos(struct node *,int);
struct node * delete_beg(struct node *);
struct node * delete_end(struct node *);
struct node * delete_pos(struct node *,int);
struct node * reverse(struct node *);
void display(struct node *);
struct node * merge(struct node *,struct node *);
struct node * delete_data(struct node *,int);
main()
{
    int ch,pos,d;
    char t;
    struct node *head=NULL,*head1=NULL;
    while(1)
    {
        printf("Enter\n1:To add at beg\n2:To add at the end\n3:To add at a pos\n4:To display\n5:To delete from beg\n6:To delete from the end\n7:To delete from the pos\n");
        printf("8:To reverse\n");
        printf("9:To create2lists\n");
        printf("10:To merge\n");
        printf("11:To delete by data\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=add_beg(head);
                    break;
            case 2: head=add_end(head);
                    break;
            case 3: printf("Enter the pos\n");
                    scanf("%d",&pos);
                    head=add_pos(head,pos);
                    break;
            case 4: display(head);
                    break;
            case 5: if(head==NULL)
                    {
                        printf("List is empty\n");
                    }
                    else
                    {
                        head=delete_beg(head);
                    }
                    break;
            case 6:  if(head==NULL)
                    {
                        printf("List is empty\n");
                    }
                    else
                    {
                        head=delete_end(head);
                    }
                    break;
             case 7: if(head==NULL)
                      {
                        printf("List is empty\n");
                      }
                      else
                      {
                          printf("Enter the pos\n");
                          scanf("%d",&pos);
                          head=delete_pos(head,pos);
                      }
                      break;
             case 8: head=reverse(head);
                      break;
             case 9:  printf("Enter o to add in list one\n");
                      scanf("%*c%c",&t);
                       if(t =='o')
                       {
                           head=add_beg(head);
                       }
                       else
                       {
                           head1=add_beg(head1);
                       }
                       break;
                 case 10: head=merge(head,head1);
                          break;
                 case 11: printf("Enter the data\n");
                          scanf("%d",&d);
                          head=delete_data(head,d);
                          break;
        }
    }
}
struct node * getnode()
{
   struct node *newnode;
   newnode= (struct node *)malloc(sizeof(struct node));
   printf("Enter the name\n");
   scanf("%s",newnode->name);
   printf("Enter the data\n");
   scanf("%d",&newnode->data);
   newnode->next=NULL;
   return newnode;
}
struct node * add_beg(struct node *head)
{
   struct node *newnode=getnode();
   newnode->next=head;
   head=newnode;
   return head;
}
struct node * add_end(struct node *head)
{
  struct node *newnode=getnode();
  struct node *cur;
  if(head==NULL)
  {
      head=newnode;
      return head;
  }
  else
  {
      cur=head;
      while(cur->next!=NULL)
      {
          cur=cur->next;
      }
      cur->next=newnode;
      return head;
  }
}
struct node * add_pos(struct node *head,int pos)
{
    int i;
   struct node *newnode=getnode();
   struct node *cur;
   if(pos<=0||head==NULL)
   {
       head=newnode;
       return head;
   }
   cur=head;
   for(i=0;i<pos-1&&cur->next!=NULL;i++)
   {
       cur=cur->next;
   }
   newnode->next=cur->next;
   cur->next=newnode;
   return head;
}
void display(struct node *head)
{
    struct node *cur=head;
    while(cur!=NULL)
    {
        printf("Name:%s\n",cur->name);
        printf("Data:%d\n",cur->data);
        cur=cur->next;
    }
}
struct node * delete_beg(struct node *head)
{
  struct node *cur=head;
  head=head->next;
  printf("Deleted Information\nName:%s\nData=%d\n",cur->name,cur->data);
  free(cur);
  return head;
}
struct node * delete_end(struct node *head)
{
  struct node *cur=head;
  struct node *p=NULL;
  while(cur->next!=NULL)
  {
      p=cur;
      cur=cur->next;
  }
  if(p!=NULL)
  {
      p->next=NULL;
  }
  else
  {
      head=NULL;
  }
  printf("Deleted Information\nName:%s\nData=%d\n",cur->name,cur->data);
  free(cur);
  return head;
}
struct node * delete_pos(struct node *head,int pos)
{
    int i;
   struct node *cur=head;
   struct node *p=NULL;
   if(pos<=0||head->next==NULL)
   {
       head=head->next;
       printf("Deleted Information\nName:%s\nData=%d\n",cur->name,cur->data);
       free(cur);
      return head;
   }
   for(i=0;i<pos-1&&cur->next!=NULL;i++)
   {
       p=cur;
       cur=cur->next;
   }
   p->next=cur->next;
    printf("Deleted Information\nName:%s\nData=%d\n",cur->name,cur->data);
    free(cur);
    return head;
}
struct node * reverse(struct node *head)
{
   struct node *cur=head,*p=NULL;
   while(head!=NULL)
   {
       cur=head->next;
       head->next=p;
       p=head;
       head=cur;
    }
    head=p;
    return head;
}
struct node * merge(struct node *head, struct node *head2)
{
   struct node *cur=head;
   while(cur->next!=NULL)
   {
       cur=cur->next;
   }
   cur->next=head2;
   return head;
}
struct node * delete_data(struct node *head, int d)
{
    struct node *t=NULL,*p=NULL;
    if(head->next==NULL&&head->data==d)
    {
         printf("Deleted Information\nName:%s\nData=%d\n",head->name,head->data);
         free(head);
         head=NULL;
         return head;
    }
    struct node *cur=head;
    while(cur!=NULL)
    {
        if(cur->data==d)
        {
            t=cur;
            if(p!=NULL)
            {
                p->next=cur->next;
            }
            printf("Deleted Information\nName:%s\nData=%d\n",cur->name,cur->data);
            free(t);
            p=cur;
            cur=cur->next;

        }
        else
        {
            p=cur;
            cur=cur->next;
        }
    }
    return head;
}
