#include <stdio.h>
#include <stdlib.h>

// Linked list (LL) node
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

// Insert a element
void enqueue(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        if (head->data > x)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            struct Node *p = head, *q;
            while (p && p->data < x)
            {
                q = p;
                p = p->next;
            }
            temp->next = q->next;
            q->next = temp;
        }
    }
}

// delete an element
void dequeue()
{
    struct Node *t = head;
    head = head->next;
    free(t);
}

// display a queue of LL
void display()
{
    struct Node *p = head;
    while (p)
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