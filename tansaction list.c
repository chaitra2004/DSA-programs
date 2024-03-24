#include<stdio.h>
struct transaction
{
    char name[20];
    char trans_id[20];
    char benf_id[20];
    float amount;
    struct transaction *next;
};
struct transaction *getnode();
struct transaction * add_node(struct transaction *, int);
void total_a(struct transaction *);
void display(struct transaction *, char []);
struct transaction *delete_id(struct transaction *,char []);
main()
{
    int ch,pos;
    char n[20],t[20];
    struct transaction *head=NULL;
    while(1)
    {
        printf("Enter\n1:To add a node\n2:To display based on name\n3:to delete based oh transction id\n4:To calculate total amount\n");
         scanf("%d",&ch);
         switch(ch)
         {
             case 1: printf("Enter the pos\n");
                     scanf("%d",&pos);
                     head= add_node(head,pos);
                     break;
             case 2: if(head!=NULL)
                      {
                          printf("Enter the name\n");
                          scanf("%s",n);
                          display(head,n);
                      }
                       else
                       {
                           printf("List is empty\n");
                       }
                       break;
             case 3:if(head!=NULL)
                      {
                          printf("Enter the trans_id\n");
                          scanf("%s",t);
                          head=delete_id(head,t);
                      }
                       else
                       {
                           printf("List is empty\n");
                       }
                       break;

             case 4: total_a(head);
                     break;
         }
    }
}
struct transaction *getnode()
{
    struct transaction *newnode;
    newnode =(struct transaction *)malloc(sizeof(struct transaction));
    printf("Enter the name\n");
    scanf("%s",newnode->name);
    printf("Enter the trans_id\n");
    scanf("%s",newnode->trans_id);
    printf("Enter the benf_id\n");
    scanf("%s",newnode->benf_id);
    printf("Enter the amount\n");
    scanf("%f",&newnode->amount);
    newnode->next=NULL;
    return newnode;
}
struct transaction *add_node(struct transaction *head, int pos)
{
   int i;
   struct transaction *newnode=getnode();
   if(pos<=0||head==NULL)
   {
       newnode->next=head;
       head=newnode;
       return head;
   }
   struct transaction *cur=head;
   for(i=0;i<pos-1&&cur->next!=NULL;i++)
   {
       cur=cur->next;
   }
    newnode->next=cur->next;
    cur->next=newnode;
    return head;
}
void total_a(struct transaction *head)
{
    struct transaction *cur =head;
    float a=0;
    while(cur!=NULL)
    {
        a=a+cur->amount;
        cur=cur->next;
    }
    printf("A=%f\n",a);
}
void display(struct transaction *head, char n[20])
{
    struct  transaction *cur=head;
    struct  transaction *p=NULL;
    if(head->next==NULL && strcasecmp(head->name,n)==0)
    {
        printf("Name=%s\nTrans_id=%s\nBenf_id=%s\nAmount=%f\n",head->name,head->trans_id,head->benf_id,head->amount);
        return NULL;
    }
    while(cur!=NULL)
    {
       if(strcasecmp(cur->name,n==0))
       {
            printf("Name=%s\nTrans_id=%s\nBenf_id=%s\nAmount=%f\n",cur->name,cur->trans_id,cur->benf_id,cur->amount);
            cur=cur->next;
            p=cur;
            return 0;
       }
       else
       {
           p=cur;
           cur=cur->next;
       }
    }
}
struct transaction * delete_id(struct transaction *head, char t[20])
{
    struct  transaction *cur=head;
    struct  transaction *p=NULL;
    struct transaction *q=NULL, *temp=NULL;
    if(head->next==NULL && strcasecmp(head->name,t)==0)
    {
       printf("Name=%s\nTrans_id=%s\nBenf_id=%s\nAmount=%f\n",head->name,head->trans_id,head->benf_id,head->amount);
        q=head;
        head=head->next;
        free(q);
        return head;
    }
    while(cur!=NULL)
    {
       if(strcasecmp(cur->name,t==0))
       {
            temp=cur;
            printf("Name=%s\nTrans_id=%s\nBenf_id=%s\nAmount=%f\n",cur->name,cur->trans_id,cur->benf_id,cur->amount);
            cur=cur->next;
            free(temp);

       }
       else
       {
           p=cur;
           cur=cur->next;
       }
    }
    return head;
}
