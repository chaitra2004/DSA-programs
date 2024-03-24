#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct book
{
    char name[30];
    int na;
    char author[5][30];
    float cost;
    int y;
    struct book *next;
};
struct book *getnode();
struct book *add_beg(struct book *);
struct book *add_end(struct book *);
struct book *add_pos(struct book *,int);
struct book *delete_beg(struct book *);
struct book *delete_end(struct book *);
struct book *delete_pos(struct book *,int);
int total(struct book *);
struct book *delete_a(struct book *,char []);
struct book *delete_y(struct book *,int);
main()
{
    int pos,yr,ch,l;
    char auth[30];
    while(1)
    {
        struct book *head=NULL;
        printf("Enter 1: To add a node at beg\n2 To add a node at end\n3 To add a node at specific pos\n4 To delete a at the beg\n5 To delete a node at the end\n6 To delete a node at specific pos\n7 To count the total no of books\n8 To delete a book of a author\n 9 To delete a book of a year\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:head=add_beg(head);
                  break;
            case 2:head=add_end(head);
                  break;
            case 3:printf("Enter the position\n");
                   scanf("%d",&pos);
                   head=add_pos(head,pos);
                   break;
            case 4:if(head==NULL)
                    {
                        printf("List is empty\n");
                        break;
                    }
                    else
                     {
                         printf("Enter the pos\n");
                         scanf("%d",&pos);
                         head=delete_beg(head);
                         break;
                     }
           case 5: if(head==NULL)
                   {
                     printf("List is empty\n");
                     break;
                   }
                    else
                     {
                         printf("Enter the pos\n");
                         scanf("%d",&pos);
                         head=delete_end(head);
                         break;
                     }
           case 6:  if(head==NULL)
                    {
                        printf("List is empty\n");
                        break;
                    }
                    else
                     {
                         printf("Enter the pos\n");
                         scanf("%d",&pos);
                         head=delete_end(head);
                         break;
                     }
           case 7:if(head==NULL)
                   {
                       printf("List is empty\n");
                       break;
                   }
                   else
                   {
                       l=total(head);
                       printf("Total books=%d",l);
                       break;
                   }
            case 8: if(head==NULL)
                   {
                       printf("List is empty\n");
                       break;
                   }
                   else
                   {
                       printf("Enter the name of author\n");
                       scanf("%s",auth);
                       head=delete_a(head,auth);
                       break;
                   }
            case 9: if(head==NULL)
                   {
                       printf("List is empty\n");
                       break;
                   }
                   else
                   {
                       printf("Enter the year\n");
                       scanf("%d",&yr);
                       head=delete_y(head,yr);
                       break;
                   }
        }
    }
}
struct book *getnode()
{
    int i;
   struct book *newnode;
   newnode=(struct book*)malloc(sizeof(struct book));
   printf("Enter the name\n");
   scanf("%s",newnode->name);
   printf("Enter the no of authors\n");
   scanf("%d",&newnode->na);
   printf("Enter the name of authors\n");
   for(i=0;i<newnode->na;i++)
   {
      scanf("%s",newnode->author[i]);
   }
   printf("Enter the cost of the book\n");
   scanf("%f",&newnode->cost);
   printf("Enter the year\n");
   scanf("%d",&newnode->y);
   newnode->next=NULL;
   return newnode;
}
struct book *add_beg(struct book *head)
{
  struct book*newnode=getnode();
  newnode->next=head;
  head=newnode;
  return head;
}
struct book *add_end(struct book *head)
{
  struct book *newnode=getnode();
  struct book *cur=head;
  if(head==NULL)
  {
      newnode->next=head;
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
struct book *add_pos(struct book *head,int pos)
{
  int i;
  struct book *newnode=getnode();
  struct book *cur =head;
  if(pos<=0||head==NULL)
  {
      newnode->next=head;
      head=newnode;
      return head;
  }
  for(i=0;i<pos-1&&cur->next!=NULL;i++)
  {
      cur=cur->next;
  }
  newnode->next=cur->next;
  cur->next=newnode;
  return head;
}
struct book *delete_beg(struct book *head)
{
    int i;
   struct book *newnode=getnode();
   struct book *cur=head;
   head=head->next;
   printf("\nDeleted Information\n");
   printf("Name:%s",cur->name);
   printf("No of auth:%d",cur->na);
   for(i=0;i<cur->na;i++)
   {
       printf("%s",cur->author[i]);
   }
   printf("Cost:%f",cur->cost);
   printf("Year:%d",cur->y);
   free(cur);
   return head;
}
struct book *delete_end(struct book *head)
{
    int i;
   struct book *cur=head;
   struct book *p=NULL;
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
   printf("\nDeleted Information\n");
   printf("Name:%s",cur->name);
   printf("No of auth:%d",cur->na);
   for(i=0;i<cur->na;i++)
   {
       printf("%s",cur->author[i]);
   }
   printf("Cost:%f",cur->cost);
   printf("Year:%d",cur->y);
   free(cur);
   return head;
}
struct book *delete_pos(struct book *head,int pos)
{
    int i;
  struct book *newnode=getnode();
  struct book *cur=head;
  struct book *p=NULL;
   if(pos<=0||head==NULL)
   {
       head=head->next;
     printf("\nDeleted Information\n");
     printf("Name:%s",cur->name);
     printf("No of auth:%d",cur->na);
     for(i=0;i<cur->na;i++)
     {
       printf("%s",cur->author[i]);
     }
     printf("Cost:%f",cur->cost);
     printf("Year:%d",cur->y);
     free(cur);
     return head;
   }
  for(i=0;i<pos-1&&cur->next!=NULL;i++)
  {
      p=cur;
      cur=cur->next;
  }
  p->next=cur->next;
  printf("\nDeleted Information\n");
    printf("Name:%s",cur->name);
     printf("No of auth:%d",cur->na);
     for(i=0;i<cur->na;i++)
     {
       printf("%s",cur->author[i]);
     }
     printf("Cost:%f",cur->cost);
     printf("Year:%d",cur->y);
     free(cur);
     return head;
}
int total(struct book *head)
{
    int l=0;
    struct book *cur=head;
    while(cur->next!=NULL)
    {
        l++;
        cur=cur->next;
    }
    return l;
}
struct book *delete_a(struct book *head,char auth[30])
{
    int i;
   struct book *cur=head;
   struct book *p=NULL;
   while(cur!=NULL)
   {
       if(strcasecmp(cur->author,auth)==0)
       {
           if(p!=NULL)
            p->next=cur->next;
           else
           {
               head=head->next;
               printf("\nDeleted Information\n");
               printf("Name:%s",cur->name);
               printf("No of auth:%d",cur->na);
              for(i=0;i<cur->na;i++)
               {
                printf("%s",cur->author[i]);
               }
               printf("Cost:%f",cur->cost);
               printf("Year:%d",cur->y);
               free(cur);
               return head;
          }
          p=cur;
          cur=cur->next;
       }
   }
   return head;
}
struct book *delete_y(struct book *head,int yr)
{
    int i;
   struct book *newnode=getnode();
   struct book *cur=head;
   struct book *p=NULL;
   while(cur->next!=NULL)
   {
     if(cur->y==yr)
       {
           if(p!=NULL)
            p->next=cur->next;
           else
           {
               head=head->next;
               printf("\nDeleted Information\n");
               printf("Name:%s",cur->name);
               printf("No of auth:%d",cur->na);
              for(i=0;i<cur->na;i++)
               {
                printf("%s",cur->author[i]);
               }
               printf("Cost:%f",cur->cost);
               printf("Year:%d",cur->y);
               free(cur);
               return head;
          }
          p=cur;
          cur=cur->next;
       }
   }
   return head;
}



