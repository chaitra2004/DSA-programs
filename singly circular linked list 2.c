#include<stdio.h>
struct node
{
    int data;
    char name[20];
    struct node *next;
};
struct node * getnode();
struct node * add_beg(struct node *);
struct node * add_end(struct node *);
void display(struct node *);
struct node * add_pos(struct node *,int);
struct node * delete_beg(struct node *);
struct node * delete_end(struct node *);
struct node * delete_pos(struct node *, int);

main()
{
    int ch,pos;
    struct node *tail=NULL;
    while(1)
    {
        printf("Enter\n1:To add at beg\n2:To add at end\n3:To display\n4:to add at pos\n5:To delete at beg\n6:to delete from end\n7:to delete from pos\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: tail = add_beg(tail);
                    break;
            case 2: tail = add_end(tail);
                    break;
            case 3: display(tail);
                    break;
            case 4: printf("Enter the pos\n");
                    scanf("%d",&pos);
                    tail= add_pos(tail,pos);
                    break;
            case 5: tail= delete_beg(tail);
                    break;
            case 6: tail=delete_end(tail);
                     break;
            case 7: if(tail==NULL)
                      {
                         printf("List is empty\n");
                      }
                   else
                   {
                       printf("Enter the pos\n");
                       scanf("%d",&pos);
                       tail= delete_pos(tail,pos);
                    }
                    break;
        }
    }
}
struct node * getnode()
{
   struct node *newnode;
   newnode = (struct node *)malloc(sizeof(struct node));
   printf("Enter the data\n");
   scanf("%d",&newnode->data);
   printf("Enter the name\n");
   scanf("%s",newnode->name);
   newnode->next=newnode;
   return newnode;
}
struct node * add_beg(struct node *tail)
{
  struct node * newnode=getnode();
  if(tail==NULL)
  {
      tail=newnode;
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
void display(struct node *tail)
{
    struct node *cur=tail->next;
    do
    {
        printf("Data:%d\n",cur->data);
        printf("Name:%s\n",cur->name);
        cur=cur->next;
    }while(cur!=tail->next);
}
struct node * add_pos(struct node *tail,int pos)
{
    int i;
   struct node *newnode =getnode();
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
struct node * delete_beg(struct node *tail)
{
    struct node *cur;
    if(tail==NULL)
    {
        printf("list is empty\n");
    }
    cur=tail->next;
    if(cur==tail)
    {
        printf("Deleted Information\nData=%d\nName=%s\n",cur->data,cur->name);
        free(cur);
        tail=NULL;
        return tail;
    }
    tail->next=cur->next;
    printf("Deleted Information\nData=%d\nName=%s\n",cur->data,cur->name);
    free(cur);
    return tail;
}
struct node * delete_end(struct node *tail)
{
  struct node *cur=tail->next;
  if(tail==NULL)
  {
      printf("List is empty\n");
      return 0;
  }
  if(cur==tail)
  {
       printf("Deleted Information\nData=%d\nName=%s\n",cur->data,cur->name);
        free(cur);
        tail=NULL;
        return tail;
  }
  while(cur->next!=tail)
  {
      cur=cur->next;
  }
  cur->next=tail->next;
     printf("Deleted Information\nData=%d\nName=%s\n",tail->data,tail->name);
        free(cur);
        tail=cur;
        return tail;
}
struct node * delete_pos( struct node *tail, int pos)
{
    int i;
   struct node *cur=tail->next;
   struct node *p=NULL;
   if(tail==cur||pos<=0)
   {

       printf("Deleted Information\nData=%d\nName=%s\n",cur->data,cur->name);
        free(cur);
        tail=NULL;
        return tail;
   }
   if(tail->next=tail)
   {

       printf("Deleted Information\nData=%d\nName=%s\n",cur->data,cur->name);
        free(cur);
        tail=NULL;
        return tail;
   }
   for(i=0;i<pos-1&&cur!=tail->next;i++)
   {
       p=cur;
       cur=cur->next;
   }
   p->next=cur->next;
   printf("Deleted Information\nData=%d\nName=%s\n",cur->data,cur->name);
   free(cur);
   if(cur==tail)
   {
       tail=p;
   }
   return tail;
}
