struct node *reverse(struct node *head);\\singly linked list
{
    struct node *cur=head, *p=NULL;
    while(head!=NULL)
    {
        cur=head->next;
        head->next=p;
        p=head;
        head=cur;
    }
    head=p;
    return head;
};
struct node *reverse(struct node *head);\\doubly linked list
{
    if(head->next==NULL)
    {
        return head;
    }
    struct node *cur=head,*t,*n=cur->next;
    while(cur!=NULL)
    {
        t=cur->next;
        cur->next=cur->prev;
        cur->prev=t;
        head=cur;
        cur=n;
        if(n!=NULL)
            n=n->next;
    }
    return head;
};
