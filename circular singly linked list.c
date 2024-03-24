#include<stdio.h>
#include<string.h>
struct node
{
    int data;
    struct node *next;
};
struct node *getnode();
struct node *add_beg(struct node*);
struct node *add_end(struct node*);
void display(struct node*);
struct node *delete_beg(struct node*);
struct node *delete_end(struct node*);
struct node *add_pos(struct node*,int);
struct node *delete_pos(struct node *,int);
int length(struct node*);
struct node *rev(struct node *);
struct node * merge(struct node *,struct node *);
struct node * delete_data(struct node *,int);
main()
{
    struct node *tail=NULL,*tail1=NULL;
    int ch,pos,l;
    char c;
    while(1)
    {
        printf("\nEnter\n1:To add a node at beg\n2:To add node at end\n3:To display the nodes\n4:To delete node from the beg\n5:To delete node from the end\n6 To add a node at specific pos\n7 To delete a node from the specific pos\n8 To calculate the total length\n");
        printf("9:To reverse\n");
        printf("10:To create to lists\n");
        printf("11:To merge \n");
        printf("12:To delete by data\n");
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
                     {
                        printf("List is empty\n");
                     }
                     else
                     {
                         tail=delete_beg(tail);
                     }
                     break;
             case 5:if(tail==NULL)
                     {
                        printf("List is empty\n");
                     }
                     else
                     {
                         tail=delete_end(tail);
                     }
                     break;
             case 6:printf("Enter the pos\n");
                    scanf("%d",&pos);
                    tail=add_pos(tail,pos);
                    break;
             case 7:if(tail!=NULL)
                    {
                        printf("Enter the pos\n");
                        scanf("%d",&pos);
                        tail=delete_pos(tail,pos);
                    }
                    else
                    {
                        printf("\nList is empty\n");
                    }
                    break;
             case 8:l=length(tail);
                     printf("Length=%d\n",l);
                     break;
             case 9: tail=rev(tail);
                        break;
             case 10: printf("Enter o to add at list one\n");
                       scanf("%*c%c",&c);
                       if(c=='o')
                       {
                           tail=add_beg(tail);
                       }
                       else
                       {
                           tail1=add_beg(tail1);
                       }
                       break;
            case 11: tail=merge(tail,tail1);
                      break;
            case 12:  if(tail!=NULL)
                    {
                        printf("Enter the data\n");
                        scanf("%d",&pos);
                        tail=delete_data(tail,pos);
                    }
                    else
                    {
                        printf("\nList is empty\n");
                    }
                    break;
        }
    }
}
struct node *getnode()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&newnode->data);
    newnode->next=newnode;
    return newnode;
}
struct node *add_beg(struct node *tail)
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
struct node *add_end(struct node *tail)
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
    struct node *cur;
    if(tail==NULL)
    {
        printf("List is empty\n");
        return 0;
    }
    cur=tail->next;
   do
    {
        printf("Data:%d\n",cur->data);
        cur=cur->next;
    }while(cur!=tail->next);
}
struct node *delete_beg(struct node *tail)
{
   struct node *cur;
   cur=tail->next;
   if(cur==tail)
   {
       printf("Deleted information\n%d\n",cur->data);
       free(cur);
       tail=NULL;
       return tail;
   }
   tail->next=cur->next;
   printf("Deleted information\n%d\n",cur->data);
   free(cur);
   return tail;
}
struct node *delete_end(struct node* tail)
{
   struct node *cur;
   cur=tail->next;
   if(cur==tail)
   {
       printf("Deleted information\n%d\n",cur->data);
       free(cur);
       tail=NULL;
       return tail;
   }
   while(cur->next!=tail)
   {
       cur=cur->next;
   }
   cur->next=tail->next;
   printf("Deleted information\n%d\n",tail->data);
   free(tail);
   tail=cur;
   return tail;
}
struct node *add_pos(struct node *tail,int pos)
{
    int i;
   struct node *newnode=getnode();
   struct node*cur=tail->next;
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
   for(i=0;i<pos-1&&cur!=tail;i++)
   {
       cur=cur->next;
   }
   newnode->next=cur->next;
   cur->next=newnode;
   if(cur==tail)
   {
       tail=newnode;
   }
   return tail;
}
struct node *delete_pos(struct node *tail,int pos)
{
   int i;
   struct node *cur=tail->next;
   struct node *p=NULL;
   if(pos<=1)
   {
       tail->next=cur->next;
       printf("Deleted information\n%d\n",cur->data);
       free(cur);
       return tail;
   }
  for(i=0;i<pos-1&&cur!=tail;i++)
        {
           p=cur;
           cur=cur->next;
        }
        p->next=cur->next;
        printf("Deleted information\n%d\n",cur->data);
        free(cur);
        if(cur==tail)
         {
            tail=p;
         }
        return tail;
}

int length(struct node *tail)
{
    struct node *cur=tail->next;
    int l=0;
     do
    {
        cur=cur->next;
        l++;
    }while(cur!=tail->next);
   return l;
}
struct node * rev(struct node *tail)
 {
    struct node *p=NULL,*cur=tail->next,*t=cur->next;
    while(cur!=tail)
    {
        p=cur;
        cur=t;
        t=cur->next;
        cur->next=p;
    }
    t->next=tail;
    tail=t;
    return tail;
 }
 struct node * merge(struct node *tail,struct node *tail1)
 {
     struct node *cur=tail->next;
     tail->next=tail1->next;
     tail1->next=cur;
     return tail1;
 }
struct node * delete_data(struct node *tail,int d)
{
  struct node *cur=tail->next;
  struct node *p=tail;
  struct node *t=NULL;
  if(tail->next==tail && tail->data==d)
  {

      printf("Deleted information\nData:%d\n",tail->data);
      free(tail);
      tail=NULL;
      return tail;
  }
  while(cur!=tail)
  {
      if(cur->data==d)
      {
            printf("Deleted information\nData:%d\n",cur->data);
            t=cur;
            cur=cur->next;
            p->next=cur;
            free(t);
      }
      else
      {
          p=cur;
          cur=cur->next;
      }
  }
  if(cur->data==d)
  {
       p->next=tail->next;
       printf("Deleted information\nData:%d\n",cur->data);
       free(cur);
       tail=p;
  }
  return tail;
}
