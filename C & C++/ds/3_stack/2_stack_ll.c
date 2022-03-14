#include <stdio.h>
#include <stdlib.h>

// creating node for Singly Linked List (ll)
struct node
{
    int data;
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
int pop()
{
    int x = -1;
    if (top == NULL)
        printf("Stack Underflow\n");
    else
    {
        struct node *t;
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

// display
void display()
{
    struct node *p;
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    return 0;
}