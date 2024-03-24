#include <stdio.h>
#include <string.h>

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
struct Stack
{
    int top;
    int array[MAXSIZE];
} st;
void initialize()
{
 st.top = -1;
}
int isFull()
{
    if(st.top >= MAXSIZE-1)
        return TRUE;
    else
        return FALSE;
}
int isEmpty()
{
 if(st.top == -1)
     return TRUE;
 else
     return FALSE;
}
void push(int num)
{
    if (isFull())
        printf("Stack is Full...\n");
    else {
        st.array[st.top + 1] = num;
        st.top++;
    }
}
int pop()
{
    if (isEmpty())
        printf("Stack is Empty...\n");
    else {
     st.top = st.top - 1;
        return st.array[st.top+1];
    }
}
int main()
{
    char inputString[100], c;
    int i, length;
    initialize();
    printf("Enter a string\n");
    gets(inputString);
    length = strlen(inputString);
    /* Push all characters of input String to Stack */
    for(i = 0; i < length; i++)
    {
        push(inputString[i]);
    }
    /* Poping characters from stack returs the characters of input string
      in reverse order. We will then compare it with corresponding
      characters of input string. If we found a mismatch the input
      string is not a palindrome string */
    for(i = 0; i < length; i++){
        if(pop() != inputString[i]) {
            printf("Not a Palindrome String\n");
            return 0;
        }
    }

    printf("Palindrome String\n");
    return 0;
}

