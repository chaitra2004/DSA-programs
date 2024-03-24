#include<stdio.h>
struct song
{
    char name[20];
    char singer[20];
    char movie[20];
    int dur;
    struct song *next;
};
struct song* getsong();
struct song* addsong(struct song*,int);
struct song* deletesong(struct song*,int);
void display(struct song*);
int duration(struct song*);
struct song* dlt_singer(struct song*,char[]);
main()
{
    struct song *tail=NULL,*cur=NULL;
    int pos,ch,t;
    char s[20];
    while(1)
    {
        printf("Enter 1 : To add song at specified pos\n2 : To delete the song at specified pos\n3 :To Display\n4 : To calculate total duration\n5 : To delete the song of particular singer\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : printf("enter the position\n");
                     scanf("%d",&pos);
                     tail=addsong(tail,pos);
                     break;
            case 2 : if(tail==NULL)
                     {
                         printf("List is empty\n");
                     }
                     else
                     {
                         printf("Enter the pos\n");
                         scanf("%d",&pos);
                         tail=deletesong(tail,pos);
                         break;
                     }
            case 3 : display(tail);
                     break;
            case 4 :t=duration(tail);
                    printf("Total duration : %d\n",t);
                    break;
            case 5 :if(tail!=NULL)
                    {
                        printf("Enter the singer name\n");
                        scanf("%s",s);
                        tail=dlt_singer(tail,s);
                    }
                    else
                    {
                        printf("List is empty\n");
                    }
                    break;
        }
    }
}
struct song* getsong()
{
   struct song *newsong=(struct song *)malloc(sizeof(struct song));
   printf("Enter the song name\n");
   scanf("%s",newsong->name);
   printf("Enter the singer name\n");
   scanf("%s",newsong->singer);
   printf("Enter the movie name\n");
   scanf("%s",newsong->movie);
   printf("Enter the duration of song in seconds\n");
   scanf("%d",&newsong->dur);
   newsong->next=newsong;
   return newsong;
}
struct song* addsong(struct song *tail,int pos)
{
    int i;
    struct song *nw=getsong();
    struct song *cur;
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
    cur=tail->next;
    for(i=0;i<pos-1&&cur->next!=tail;i++)
    {
        cur=cur->next;
    }
    nw->next=cur->next;
    cur->next=nw;
    if(cur==tail)
    {
       tail=nw;
    }
    return tail;
}
struct song* deletesong(struct song *tail,int pos)
{
    int i;
    struct song *cur=tail->next;
    struct song *pv=NULL;
    if(pos<=0)
    {
        tail->next=cur->next;
        printf("Deleted info : %s\t%s\t%s\t%d",cur->name,cur->singer,cur->movie,cur->dur);
        free(cur);
        return tail;
    }
    if(cur==tail)
    {
        tail=NULL;
        printf("Deleted info : %s\t%s\t%s\t%d",cur->name,cur->singer,cur->movie,cur->dur);
        free(cur);
        return tail;
    }
    for(i=0;i<pos-1&&cur!=tail;i++)
    {
        pv=cur;
        cur=cur->next;
    }
    pv->next=cur->next;
    printf("Deleted info : %s\t%s\t%s\t%d\n",cur->name,cur->singer,cur->movie,cur->dur);
    free(cur);
    if(cur==tail)
    {
        tail=pv;
    }
    return tail;
}
void display(struct song *tail)
{
    struct song *cur;
    if(tail==NULL)
    {
        printf("List is empty\n");
    }
    cur=tail->next;
    do
    {
        printf("Name:%s\tSinger:%s\tMovie:%s\tDuration:%d\n",cur->name,cur->singer,cur->movie,cur->dur);
        cur=cur->next;
    }while(cur!=tail->next);
}
int duration(struct song *tail)
{
    int t=0;
    if(tail==NULL)
    {
        t=0;
        return t;
    }
    struct song *cur=tail->next;
    do
    {
        t=t+cur->dur;
        cur=cur->next;
    }while(cur!=tail->next);
    return t;
}
struct song* dlt_singer(struct song *tail, char s[20])
{
    struct song *cur=tail->next;
    struct song *p=tail,*t=NULL;
    while(cur!=tail)
    {
        if(strcasecmp(cur->singer,s)==0)
        {
             printf("Name:%s\tSinger:%s\tMovie:%s\tDuration:%d\n",cur->name,cur->singer,cur->movie,cur->dur);
             t=cur;
             cur=cur->next;
             p->next=cur;
             free(cur);
        }
        else
        {
            p=cur;
            cur=cur->next;
        }
    }
    if(strcasecmp(cur->singer,s)==0)
    {
        p->next=tail->next;
         printf("Name:%s\tSinger:%s\tMovie:%s\tDuration:%d\n",cur->name,cur->singer,cur->movie,cur->dur);
         free(cur);
         tail=p;
    }
    return tail;
}
