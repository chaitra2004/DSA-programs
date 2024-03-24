#include<stdio.h>
#include<stdlib.h>
struct song
{
    char song;
    char singer;
    int mm;
    int ss;

};
struct node
{
    int data;
    struct node*next;
    struct node*prev;

};
struct node*newnode;
newnode=create node();
newnode=data;
if(*head=NULL)
    *head=newnode;
else
{
    newnode->next=head;
    newnode->prev=*head->prev;
    *head->prev=newnode;
    newnode->prev->next=newnode;
    *head=newnode;
}return;
void display(structnode *head);
{
    if(head==NULL)
        printf("empty list\n");
       cur=cur->next;
}
}printf("%d\n,cur->data");
else
{
    struct node*cur=head;
    do
    {
        printf("%d\t,cur->data");
        cur=cur->next;
    }
}
