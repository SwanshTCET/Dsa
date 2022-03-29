#include <stdio.h>
#include <stdlib.h>

// creating structure for a node
struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *head = NULL;

// creating circular doubly ll (CDLL)using array
void create(int a[], int n)
{
    int i;
    struct node *t, *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = a[0];
    head->next = head;
    head->prev = head;
    last = head;
    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = head;
        t->prev = last;
        last->next = t;
        head->prev = t;
        last = t;
    }
}

// Display CDLL
void display(struct node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

// counting length of a node in CDLL
int length(struct node *p)
{
    int len = 0;
    if (head == NULL)
        return len;
    do
    {
        len++;
        p = p->next;
    } while (p != head);
    return len;
}

// Insert in CDLL
void insert(struct node *p, int pos, int x)
{
    struct node *t;
    int i;
    if (pos < 0 || pos > length(head))
        return;

    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    if (pos == 0)
    {
        if (head == NULL)
        {
            t->next = t;
            t->prev = t;
            head = t;
        }
        else
        {
            t->next = head;
            t->prev = head->prev;
            head->prev = t;
            t->prev->next = t;
            head = t;
        }
    }
    else
    {
        for (i = 0; i < pos - 1; i++)
            p = p->next;
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next = p->next;
        t->prev = p;
        p->next = t;
        t->next->prev = t;
    }
}

int main()
{
    int a[] = {12};
    create(a, 1);
    display(head);
    return 0;
}