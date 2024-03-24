#include<stdio.h>
struct student
{
    char name[20];
    int rollno;
    char usn[20];
    int yoj;
    struct student *next;
};
struct student * getnode();
struct student * add_s(struct student *,int);
struct student * delete_s(struct student *,int);
void display(struct student *);
main()
{
    struct student *head=NULL;
    int ch,pos;
    while(1)
    {
        printf("\nEnter 1 To add a node\n 2 To delete a node\n 3 To display all the nodes\n ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the position\n");
                    scanf("%d",&pos);
                    head=add_s(head,pos);
                    break;
            case 2: if(head==NULL)
                    {
                        printf("List is empty\n");
                    }
                    else
                    {
                       printf("Enter the position\n");
                        scanf("%d",&pos);
                       head=delete_s(head,pos);
                    }
                    break;
            case 3:display(head);
                   break;

        }
    }
}
struct student * getnode()
{
   struct student *newnode;
   newnode=(struct student*)malloc(sizeof(struct student));
   printf("Enter the name\n");
   scanf("%s",newnode->name);
   printf("Enter the rollno\n");
   scanf("%d",&newnode->rollno);
   printf("Enter the usn\n");
   scanf("%s",newnode->usn);
   printf("Enter the yoj\n");
   scanf("%d",&newnode->yoj);
   newnode->next=NULL;
   return newnode;
}
struct student * add_s(struct student *head,int pos)
{
   struct student *cur=head;
   struct student *newnode=getnode();
   int i;
   if(pos<=0||head==NULL)
    {
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
struct student *delete_s(struct student *head,int pos)
{
    int i;
    struct student *newnode=getnode();
    struct student *cur=head;
    struct student *p=NULL;
    if(pos<=0||head==NULL)
    {
        head=head->next;
        printf("Deleted Information\n");
        printf("\nName:%s",cur->name);
        printf("\nRollno:%d",cur->rollno);
        printf("\nUsn:%s",cur->usn);
        printf("\nYOJ:%d",cur->yoj);
        free(cur);
        return head;
    }
    for(i=0;i<pos-1&&cur->next!=NULL;i++)
    {
        p=cur;
        cur=cur->next;
    }
    p->next=cur->next;
    printf("Deleted Information\n");
        printf("\nName:%s",cur->name);
        printf("\nRollno:%d",cur->rollno);
        printf("\nUsn:%s",cur->usn);
        printf("\nYOJ:%d",cur->yoj);
    free(cur);
    return head;
}
void display(struct student *head)
{
    struct student *cur=head;
    while(cur!=NULL)
    {
        printf("\nName:%s",cur->name);
        printf("\nRollno:%d",cur->rollno);
        printf("\nUsn:%s",cur->usn);
        printf("\nYOJ:%d",cur->yoj);
        cur=cur->next;
    }
}
