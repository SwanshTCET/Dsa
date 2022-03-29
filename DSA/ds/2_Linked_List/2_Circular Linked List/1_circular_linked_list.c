#include <stdio.h>
#include <stdlib.h>

// Structure for an node
struct node
{
    int data;
    struct node *next;
} * head;

// Create a circular Linked List from an array
void create(int a[], int n)
{
    int i;
    struct node *t, *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = a[0];
    head->next = head;
    last = head;
    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

// Display circular Linked List
void display(struct node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

// Return count of node
int length(struct node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != head);
    return len;
}

// Display Circular Linked List in recurrsive way
void rDisplay(struct node *p)
{
    static int flag = 0;
    if (p != head || flag == 0)
    {
        flag = 1;
        printf("%d ", p->data);
        rDisplay(p->next);
    }
    flag = 0;
}

// Insert Element in linked list
void insert(struct node *p, int index, int x)
{
    struct node *t;
    int i;
    if (index < 0 || index > length(p))
        return;
    if (index == 0)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next != head)
                p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (i = 1; i < index - 1; i++)
            p = p->next;
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

// Deleting node in a linked list
int delete (struct node *p, int index)
{
    struct node *q;
    int i, x;
    if (index < 0 || index > length(head))
        return -1;
    if (index == 1)
    {
        while (p->next != head)
            p = p->next;
        x = head->data;
        if (head == p)

        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}
int main()
{
    int a[] = {23, 2, 34, 65, 24, 53};
    create(a, 6);
    display(head);
    return 0;
}