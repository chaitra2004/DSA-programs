#include<stdio.h>
#include<stdlib.h>
struct node
{
    char name[20];
    int rollno;
    char usn[20];
    char dept[20];
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
struct node * delete_name(struct node *,char[]);
struct node * add_sorted(struct node *);
struct node * rev(struct node *);
main()
{
    struct node *head=NULL;
    int ch,pos;
    char n[20];
    while(1)
    {
        printf("Enter\n1:To add at beg\n");
        printf("2:To add at end\n");
        printf("3:To display\n");
        printf("4:To delete at beg\n");
        printf("5:To delete at end\n");
        printf("6:To add at pos\n");
        printf("7:To delete at pos\n");
        printf("8:To delete based on name\n");
        printf("9:To add in sorted list\n");
        printf("10:To reverse\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=add_beg(head);
                    break;
            case 2: head=add_end(head);
                    break;
            case 3: if(head==NULL)
                     {
                         printf("List is empty\n");
                     }
                     else
                     {
                         display(head);
                     }
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
             case 5: if(head!=NULL)
                    {
                       head=delete_end(head);
                    }
                    else
                    {
                        printf("List is empty\n");
                    }
                    break;
             case 6: printf("Enter the pos\n");
                     scanf("%d",&pos);
                     head=add_pos(head,pos);
                     break;
             case 7: if(head!=NULL)
                    {
                       printf("Enter the pos\n");
                       scanf("%d",&pos);
                       head=delete_pos(head,pos);
                    }
                    else
                    {
                        printf("List is empty\n");
                    }
                    break;
             case 8: if(head!=NULL)
                    {
                       printf("Enter the name\n");
                       scanf("%s",n);
                       head=delete_name(head,n);
                    }
                    else
                    {
                        printf("List is empty\n");
                    }
                    break;
              case 9: head=add_sorted(head);
                      break;
              case 10: head=rev(head);
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
   printf("Enter the rollno\n");
   scanf("%d",&newnode->rollno);
   printf("Enter the usn\n");
   scanf("%s",newnode->usn);
   printf("Enter the dept\n");
   scanf("%s",newnode->dept);
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
  newnode->prev=head->prev;
  newnode->prev->next=newnode;
  head->prev=newnode;
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
        printf("Name:%s\n",cur->name);
        printf("Rollno:%d\n",cur->rollno);
        printf("USN:%s\n",cur->usn);
        printf("Dept:%s\n\n",cur->dept);
        cur=cur->next;
    }while(cur!=head);
}
struct node * delete_beg(struct node *head)
{
  if(head->next==head)
  {
      printf("Deleted information\n");
      printf("Name:%s\n",head->name);
      printf("Rollno:%d\n",head->rollno);
      printf("USN:%s\n",head->usn);
      printf("Dept:%s\n\n",head->dept);
      free(head);
      head=NULL;
      return head;
  }
  struct node *cur=head;
  head=head->next;
  head->prev=cur->prev;
  cur->prev->next=head;
   printf("Deleted information\n");
   printf("Name:%s\n",cur->name);
   printf("Rollno:%d\n",cur->rollno);
   printf("USN:%s\n",cur->usn);
   printf("Dept:%s\n\n",cur->dept);
   free(cur);
   return head;
}
struct node * delete_end(struct node *head)
{
    if(head->next==head)
  {
      printf("Deleted information\n");
      printf("Name:%s\n",head->name);
      printf("Rollno:%d\n",head->rollno);
      printf("USN:%s\n",head->usn);
      printf("Dept:%s\n\n",head->dept);
      free(head);
      head=NULL;
      return head;
  }
  struct node *cur=head->prev;
  head->prev=cur->prev;
  cur->prev->next=head;
  printf("Deleted Information\n");
   printf("Name:%s\n",cur->name);
   printf("Rollno:%d\n",cur->rollno);
   printf("USN:%s\n",cur->usn);
   printf("Dept:%s\n\n",cur->dept);
   free(cur);
   return head;
}
struct node * add_pos(struct node *head, int pos)
{
    int i;
   struct node *newnode=getnode();
   if(head==NULL)
   {
       head=newnode;
       return head;
   }
   if(pos<=0)
   {
       newnode->next=head;
       newnode->prev=head->prev;
       newnode->prev->next=newnode;
       head->prev=newnode;
       head=newnode;
       return head;
   }
   struct node *p=NULL;
   struct node *cur=head;
   for(i=0;i<pos&&p!=head;i++)
   {
      p=cur;
      cur=cur->next;
   }
   newnode->next=cur;
   cur->prev=newnode;
   newnode->prev=p;
   p->next=newnode;
   return head;
}
struct node * delete_pos(struct node *head,int pos)
{
    int i;
   if(head->next==head)
   {
      printf("Deleted information\n");
      printf("Name:%s\n",head->name);
      printf("Rollno:%d\n",head->rollno);
      printf("USN:%s\n",head->usn);
      printf("Dept:%s\n\n",head->dept);
      free(head);
      head=NULL;
      return head;
   }
   struct node *cur=head;
   if(pos<=0)
   {
       head=head->next;
       head->prev=cur->prev;
       cur->prev->next=head;
       printf("Deleted information\n");
       printf("Name:%s\n",cur->name);
       printf("Rollno:%d\n",cur->rollno);
       printf("USN:%s\n",cur->usn);
       printf("Dept:%s\n\n",cur->dept);
       free(cur);
       return head;
   }
   struct node *p=NULL;
   for(i=0;i<pos&&cur->next!=head;i++)
   {
       p=cur;
       cur=cur->next;
   }
   p->next=cur->next;
   cur->next->prev=p;
    printf("Deleted information\n");
    printf("Name:%s\n",cur->name);
    printf("Rollno:%d\n",cur->rollno);
    printf("USN:%s\n",cur->usn);
    printf("Dept:%s\n\n",cur->dept);
    free(cur);
    return head;
}
struct node * delete_name(struct node *head, char n[20])
{
    if(head->next==head&&strcasecmp(head->name,n)==0)
    {
        head=delete_beg(head);
        return head;
    }
    struct node *p=head;
    struct node *cur=head->next;
    while(p->next!=head)
    {
        if(strcasecmp(cur->name,n)==0)
        {
            printf("Deleted information\n");
            printf("Name:%s\n",cur->name);
            printf("Rollno:%d\n",cur->rollno);
            printf("USN:%s\n",cur->usn);
            printf("Dept:%s\n\n",cur->dept);
            free(cur);
        }
        p=cur;
        cur=cur->next;
    }
    return head;
}
struct node * add_sorted(struct node *head)
{
    struct node *newnode=getnode();
    if(head==NULL)
    {
        head=newnode;
        return newnode;
    }
    if(newnode->rollno<=head->rollno)
    {
       newnode->next=head;
       newnode->prev=head->prev;
       newnode->prev->next=newnode;
       head->prev=newnode;
       head=newnode;
       return head;
    }
    if(newnode->rollno>=head->prev->rollno)
    {
        newnode->next=head;
        newnode->prev=head->prev;
        newnode->prev->next=newnode;
        head->prev=newnode;
        return head;
    }
    struct node *p=head;
    struct node *cur=head->next;
    while(cur->rollno<newnode->rollno)
    {
        p=cur;
        cur=cur->next;
    }
    newnode->next=cur;
    cur->prev=newnode;
    p->next=newnode;
    newnode->prev=p;
    return head;
}
struct node *rev(struct node *head)
{
    struct node *p=head,*cur=head,*t=NULL,*n=cur->next;
    while(cur->next!=head)
    {
       t=cur->next;
       cur->next=cur->prev;
       cur->prev=t;
       head=cur;
       cur=n;
       if(n!=p)
          n=n->next;
    }
    return head;
}

