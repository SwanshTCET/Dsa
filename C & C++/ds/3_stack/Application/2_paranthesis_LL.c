#include <stdio.h>
#include <stdlib.h>

// creating node for Singly Linked List (ll)
struct node
{
    char data;
    struct node *next;
} *top = NULL;

// Pushing element in stack
void push(int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
        printf("Heap is full / stack overflow \n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

// removing element from stack
void pop()
{
    if (top == NULL)
        printf("Stack Underflow\n");
    else
    {
        struct node *t;
        t = top;
        top = top->next;
        free(t);
    }
}

// checking equal number of opening and closing bracket are there or not
int isBalance(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
        {
            push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (top == NULL)
                return 0;
            pop();
        }
    }
    if (top == NULL)
        return 1;
    else
        return 0;
}
int main()
{
    char *s = "((a+B))*(c+D))";
    printf("%d",isBalance(s));
    return 0;
}