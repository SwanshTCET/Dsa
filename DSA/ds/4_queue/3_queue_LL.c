#include <stdio.h>
#include <stdlib.h>

// Linked list (LL) node
struct LL
{
    int data;
    struct LL *next;
} *front = NULL, *rear = NULL;

// Insert a element
void enqueue(int x)
{
    struct LL *t;
    t = (struct LL *)malloc(sizeof(struct LL));
    if (t == NULL)
        printf("Queue is full \n");
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

// delete an element
int dequeue()
{
    int x = -1;
    struct LL *t;
    if (front == NULL)
        printf("Queue is Empty\n");
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

// display a queue of LL
void display()
{
    struct LL *p = front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    // enqueue(23);
    return 0;
}