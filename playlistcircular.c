#include<stdio.h>
struct song
{
    char name[20];
    int dur;
    char singer[20];
    struct song *next;
};
struct song *getnode();
struct song *add_pos(struct song*,int);
struct song *delete_pos(struct song*,int);
struct song *delete_s(struct song*,char[20]);
struct song *merge_l(struct song*,struct song*);
void *display_m(struct song*,char[20]);
main()
{
    struct song *tail=NULL,*tail1=NULL,*merge=NULL;
    int ch,pos;
    char s[20];
    while(1)
    {
        printf("Enter \n1:add song\n2:delete song\n3:display all songs\n4:delete song of particular song name\n5:Merge 2 lists\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter pos\n");
            scanf("%d",&pos);
            tail=add_pos(tail,pos);
            break;
            case 3:display(tail);
            break;
            case 4:if(tail!=NULL)
            {
                printf("Enter song name\n");
                scanf("%s",s);
                tail=delete_s(tail,s);
            }
            else
                printf("list is empty\n");
            break;

            case 5:if(tail==NULL&&tail1==NULL)
            {
                printf("list if empty\n");
            }
            else
               merge=merge_l(tail,tail1);
            break;

        }
    }
}
struct song *getnode()
{
   struct song *nw=(struct song*)malloc(sizeof(struct song));
   printf("enter the data\n");
   printf("Enter name,duration of song,singer name\n");
   scanf("%s%d%s",nw->name,&nw->dur,nw->singer);
   nw->next=nw;
   return nw;
}
struct song *add_pos(struct song*tail,int pos)
{
    struct song *nw=getnode();
    if(tail==NULL)
    {
        tail=nw;
        return tail;
    }
    if(pos<=0)
    {
        nw->next=tail->next;
        tail->next=nw;
        return tail;
    }
    struct song *cur=tail->next;
    int i;
    for(i=0;i<pos-1&&cur!=tail;i++)
    {
        cur=cur->next;
    }
    nw->next=cur->next;
    cur->next=nw;
    if(cur==tail)
    {
        tail=nw;
        return tail;
    }
    return tail;
}

void display (struct song* tail)
{
    struct song *cur;
    if(tail==NULL)
    {
        printf("list is empty\n");
        return 0;
    }
    cur=tail->next;
    do
    {
        printf("Name=%s\nDuration=%d\nSinger=%s\n\n",cur->name,cur->dur,cur->singer);
        cur=cur->next;
    }while(cur!=tail->next);
}

struct song *delete_s(struct song* tail,char s[20])
{
    struct song *cur=tail->next;
    struct song *p=tail,*t=NULL;
    if(tail->next==tail&&strcasecmp(tail->name,s)==0)
    {
         printf("Deleted info: Name:%s\tSinger:%s\tDuration:%d\n",tail->name,tail->singer,tail->dur);
         free(tail);
         tail=NULL;
         return tail;
    }
    while(cur!=tail)
    {
        if(strcasecmp(cur->name,s)==0)
        {
             printf("Name:%s\tSinger:%s\tDuration:%d\n",cur->name,cur->singer,cur->dur);
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
    if(strcasecmp(cur->name,s)==0)
    {
         p->next=tail->next;
         printf("Name:%s\tSinger:%s\tDuration:%d\n",cur->name,cur->singer,cur->dur);
         free(cur);
         tail=p;
    }
    return tail;
}

struct song *merge_l(struct song *tail,struct song *tail1)
{
    struct song *temp=tail->next;
    if(tail==NULL&&tail1==NULL)
    {
        tail=NULL;
        return tail;
    }
    else if(tail!=NULL&&tail1==NULL)
    {
        return tail;
    }
    else if(tail==NULL&&tail1!=NULL)
    {
        return tail;
    }
    else
    {
        tail->next=tail1->next;
        tail1->next=temp;
        return tail1;
    }
}
