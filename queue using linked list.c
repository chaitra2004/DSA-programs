#include<stdio.h>
#include<stdlib.h>

// structure of a node
struct node
{
    int data;
    struct node* next;
};

// globally declared pointers
struct node* front = NULL;
struct node* rear = NULL;

// function prototyping
void enqueue(int);
int dequeue();
void display();
struct node* create(int);
int isEmpty();

int main()
{
    int user_choice, data;
    char user_active = 'Y';

    while (user_active == 'Y' || user_active == 'y')
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &user_choice);

        switch(user_choice)
        {
            case 1:
                printf("\nEnter Data: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                if (!isEmpty())
                {
                    data = dequeue();
                    printf("\n* %d was removed\n", data);
                }
                else
                {
                    printf("\nQueue is Empty!\n");
                }
                break;

            case 3:
                display();
                printf("\n");
                break;

            case 4:
                printf("\n\tProgram was Terminated!\n\n");
                return 1;

            default:
                printf("\n\tInvalid Choice\n");
        }

        printf("\nDo You want to continue? ");
        fflush(stdin);
        scanf(" %c", &user_active);
    }
    return 0;
}


// creates a new node
struct node* create(int data)
{
    struct node* new_node = (struct node*) malloc (sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\n Memory can't be allocated\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

// check if the queue is empty
int isEmpty()
{
    if (front == NULL || rear == NULL)
    {
        return 1;
    }
    return 0;
}

// inserts an item to the queue
void enqueue(int data)
{
    struct node* new_node = create(data);

    if (new_node != NULL)
    {
        // if the queue is empty
        if(front == NULL)
        {
            front = new_node;
        }
        else
        {
            rear->next = new_node;
        }
        // rear pointing to the new node
        rear = new_node;
        printf("\n* %d was inserted!\n", data);
    }
}

// removes an item to the queue
int dequeue()
{
    if (!isEmpty())
    {
        int data = front->data;
        front = front->next;
        return data;
    }
}

// display the queue
void display()
{
    if (isEmpty())
    {
        printf("\nQueue is Empty!\n");
        return;
    }
    printf("\n");
    struct node* temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
