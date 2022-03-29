#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// creating node for Singly Linked List (ll)
struct node
{
    char data;
    struct node *next;
} *top = NULL;

// Pushing element in stack
void push(char x)
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
    char x = -1;
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
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

// pre checking
int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

// operator or operand checking
int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    return 1;
}

// coversion of infix to postfix
char *in_po(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 2) * sizeof(char));
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (pre(infix[i]) > pre(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while (top != NULL)
        postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix ="a+b*c";
    push('#');
    char *postfix = in_po(infix);
    printf("%s \n", postfix);
    display();
    return 0;
}