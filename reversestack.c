#include <stdio.h>
#include <string.h>
struct Stack
{
    int top;
    char items[100];
};

int main()
{
    char string[100];
    printf("Enter a string: ");
    scanf("%s",string);
    reverseString(string);
    printf("Reversed string: %s\n", string);
    return 0;
}
void push(struct Stack* stack, char item)
{
    if (stack->top == 100 - 1) {
        printf("Stack Overflow\n");
    } else {
        stack->items[++(stack->top)] = item;
    }
}
char pop(struct Stack* stack) {
    if (stack->top == -1)
        {
        printf("Stack Underflow\n");
        return '\0';
    }
    else
    {
        return stack->items[(stack->top)--];
    }
}
void reverseString(char* string)
{
    struct Stack stack;
    initstack(&stack);
    int i;
    for (i = 0; i < strlen(string); i++)
    {
        push(&stack, string[i]);
    }
    for (i = 0; i < strlen(string); i++)
    {
        string[i] = pop(&stack);
    }
}
void initstack(struct Stack *stack)
{
    stack->top=-1;
}
