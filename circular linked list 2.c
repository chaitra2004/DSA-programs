#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
void display(struct node *);
struct node * delete_beg(struct node *);
struct node * delete_end(struct node *);
struct node * delete_pos(struct node *,int);
struct node * delete_name(struct node *,char []);
struct node * delete_data(struct node *,int);
struct node * reverse(struct node *);
main()
{
    int ch,pos,d;
    char n[20];
    struct node *tail=NULL;
    while(1)
    {
        printf("\nEnter\n1:To add at the beg\n2:To add at end\n3:To add a pos\n4:To display\n5:To delete from the beg\n6:To delete from the end\n7:To delete from thr pos\n8:To delete by the name\n9:To delete by data\n");
        printf("10: To reverse\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: tail= add_beg(tail);
                    break;
            case 2: tail= add_end(tail);
                    break;
            case 3: printf("Enter the position\n");
                    scanf("%d",&pos);
                    tail= add_pos(tail,pos);
                    break;
            case 4: display(tail);
                    break;
            case 5: if(tail==NULL)
                    {
                        printf("List is empty\n");
                    }
                    else
                    {
                        tail=delete_beg(tail);
                    }
                    break;
             case 6: if(tail==NULL)
                    {
                        printf("List is empty\n");
                    }
                    else
                    {
                        tail=delete_beg(tail);
                    }
                    break;
             case 7: if(tail==NULL)
                    {
                        printf("List is empty\n");
                    }
                    else
                    {
                        printf("Enter the pos\n");
                        scanf("%d",&pos);
                        tail=delete_pos(tail,pos);
                    }
                    break;
             case 8: if(tail!=NULL)
                     {
                        printf("Enter the name\n");
                        scanf("%s",n);
                        tail=delete_name(tail,n);
                     }
                     else
                     {
                       printf("List is empty\n");
                     }
              case 9:if(tail!=NULL)
                     {
                        printf("Enter the data\n");
                        scanf("%d",&d);
                        tail=delete_data(tail,n);
                     }
                     else
                     {
                       printf("List is empty\n");
                     }
                case 10: tail=reverse(tail);
                         break;
        }
    }
}
struct node * getnode()
{
   struct node *newnode;
   newnode=(struct node *)malloc(sizeof(struct node));
   printf("Enter the name\n");
   scanf("%s",newnode->name);
   printf("Enter the data\n");
   scanf("%d",&newnode->data);
   newnode->next=newnode;
   return newnode;
}
struct node * add_beg(struct node *tail)
{
  struct node *newnode=getnode();
  if(tail==NULL)
  {
      tail==newnode;
      return tail;
  }
  newnode->next=tail->next;
  tail->next=newnode;
  return tail;
}
struct node * add_end(struct node *tail)
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
struct node * add_pos(struct node *tail, int pos)
{
    int i;
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
  for(i=0;i<pos-1&&cur!=tail;i++)
  {
      cur=cur->next;
  }
  newnode->next=cur->next;
  cur->next=newnode;
  if(tail==cur)
  {
      tail=newnode;
  }
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
       printf("Name:%s\n",cur->name);
       printf("Data:%d\n",cur->data);
       cur=cur->next;
    }while(cur!=tail->next);
}
struct node * delete_beg(struct node *tail)
{
   struct node *cur=tail->next;
   if(cur==tail)
   {
       printf("Deleted information\nName:%s\nData:%d\n",cur->name,cur->data);
       free(cur);
       tail=NULL;
       return tail;
   }
   tail->next=cur->next;
   printf("Deleted information\nName:%s\nData:%d\n",cur->name,cur->data);
   free(cur);
   return tail;
}
struct node * delete_end(struct node *tail)
{
   struct node *cur=tail->next;
    if(cur==tail)
   {
       printf("Deleted information\nName:%s\nData:%d\n",cur->name,cur->data);
       free(cur);
       tail=NULL;
       return tail;
   }
   do
   {
       cur=cur->next;
   }while(cur!=tail->next);
   cur->next=tail->next;
   printf("Deleted information\nName:%s\nData:%d\n",tail->name,tail->data);
   free(tail);
   tail=cur;
   return tail;
}
struct node * delete_pos(struct node *tail,int pos)
{
    int i;
   struct node *cur=tail->next;
   struct node *p=NULL;
   if(tail==cur)
   {
       printf("Deleted information\nName:%s\nData:%d\n",cur->name,cur->data);
       free(cur);
       tail=NULL;
       return tail;
   }
   if(pos<=0)
   {
       tail->next=cur->next;
       printf("Deleted information\nName:%s\nData:%d\n",cur->name,cur->data);
       free(cur);
       return tail;
   }
   for(i=0;i<pos-1&&cur!=tail;i++)
   {
       p=cur;
       cur=cur->next;
   }
   p->next=cur->next;
   printf("Deleted information\nName:%s\nData:%d\n",tail->name,tail->data);
   free(cur);
   if(tail==cur)
   {
       tail=p;
   }
   return tail;
}
struct node *delete_name(struct node *tail ,char n[20])
{
   struct node *cur=tail->next;
   struct node *p=tail;
   struct node *t=NULL;
   if(tail->next==tail&&strcasecmp(tail->name,n)==0)
   {
       printf("Deleted information\nName:%s\nData:%d\n",tail->name,tail->data);
       free(tail);
       tail=NULL;
       return tail;
   }
   while(cur!=tail)
   {
       if(strcasecmp(cur->name,n)==0)
       {
            printf("Deleted information\nName:%s\nData:%d\n",cur->name,cur->data);
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
   if(strcasecmp(cur->name,n)==0)
   {
       p->next=tail->next;
       printf("Deleted information\nName:%s\nData:%d\n",cur->name,cur->data);
       free(cur);
       tail=p;
   }
   return tail;
}
struct node * delete_data(struct node *tail,int d)
{
  struct node *cur=tail->next;
  struct node *p=tail;
  struct node *t=NULL;
  if(tail->next==tail && tail->data==d)
  {

      printf("Deleted information\nName:%s\nData:%d\n",tail->name,tail->data);
      free(tail);
      tail=NULL;
      return tail;
  }
  while(cur!=tail)
  {
      if(cur->data==d)
      {
            printf("Deleted information\nName:%s\nData:%d\n",cur->name,cur->data);
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
       printf("Deleted information\nName:%s\nData:%d\n",cur->name,cur->data);
       free(cur);
       tail=p;
  }
  return tail;
}
 struct node * reverse(struct node *tail)
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
