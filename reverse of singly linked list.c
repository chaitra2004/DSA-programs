#include<stdio.h>
struct node
{
    char name[20];
    int data;
    struct node *next;
};
struct node * getnode();
struct node * add_beg(struct node *);
void display(struct node *);
main()
{
    int ch,pos;
    struct node *head=NULL;
    while(1)
    {
        printf("Enter\n1:To add at beg\n2:To add at the end\n3:To add at a pos\n4:To display\n5:To delete from beg\n6:To delete from the end\n7:To delete from the pos\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=add_beg(head);
                    break;

