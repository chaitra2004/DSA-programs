#include<stdio.h>
struct registration
{
    char name[20];
    char reg_no[20];
    char address[20];
    float amount;
    struct registration *next;
};
struct registration * getnode();
struct registration * add_node(struct registration *);
void display(struct registration *);
struct registration * delete_node(struct registration *);
main()
{
    struct registration *head=NULL;
    int ch;
    while(1)
    {
        printf("Enter\n1:To add a registration\n");
        printf("2:To display the list\n");
        printf("3:To delete the registration\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=add_node(head);
                    break;
            case 2: if(head==NULL)
                     {
                         printf("List is empty\n");
                     }
                     else
                     {
                         display(head);
                     }
                     break;
             case 3: if(head!=NULL)
                      {
                        head=delete_node(head);
                      }
                      else
                      {
                          printf("List is empty\n");
                      }
                      break;


        }
    }
}
struct registration * getnode()
{
  struct registration *newnode;
  newnode=(struct registration *)malloc(sizeof(struct registration));
  printf("Enter the name\n");
  scanf("%s",newnode->name);
  printf("Enter the reg no\n");
  scanf("%s",newnode->reg_no);
  printf("Enter the adress\n");
  scanf("%s",newnode->address);
  printf("Enter the amount\n");
  scanf("%f",&newnode->amount);
  newnode->next=NULL;
  return newnode;
}
struct registration * add_node(struct registration *head)
{
  struct registration *newnode=getnode();
  if(head==NULL)
  {
      head=newnode;
      return head;
  }
  newnode->next=head;
  head=newnode;
  return head;
}
void display(struct registration *head)
{
    struct registration *cur=head;
    while(cur!=NULL)
    {
        printf("Name=%s\n",cur->name);
        printf("RegNo=%s\n",cur->reg_no);
        printf("Adress=%s\n",cur->address);
        printf("Amount=%f\n\n",cur->amount);
        cur=cur->next;
    }
}
struct registration * delete_node(struct registration *head)
{
   struct registration *cur=head;
   if(head->next==NULL)
   {
        printf("Deleted information\n");
        printf("Name=%s\n",head->name);
        printf("RegNo=%s\n",head->reg_no);
        printf("Adress=%s\n",head->address);
        printf("Amount=%f\n\n",head->amount);
        free(head);
        head=NULL;
        return head;
   }
    head=head->next;
    printf("Deleted information\n");
    printf("Name=%s\n",cur->name);
    printf("RegNo=%s\n",cur->reg_no);
    printf("Adress=%s\n",cur->address);
    printf("Amount=%f\n\n",cur->amount);
    free(cur);
    return head;
}
