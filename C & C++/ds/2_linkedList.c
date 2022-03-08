#include <stdio.h>
#include <stdlib.h>

// Creating Node
struct node
{
    int data;
    struct node *next;
} *first = NULL, *second = NULL, *third = NULL;

// Creating linked list
void create(int a[], int n)
{
    int i;
    struct node *t, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Below Function are recursive approach

// Recurrsive way to display linked list
void rdisplay(struct node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        rdisplay(p->next);
    }
}

// recurssive way to count node in linked list
int rcount(struct node *p)
{
    if (p)
        return rcount(p->next) + 1;
    else
        return 0;
}

// recurssive way to count total of linked list
int rsum(struct node *p)
{
    if (p != NULL)
        return rsum(p->next) + p->data;
    return 0;
}

// recurssive way to find max in linked list
int rmax(struct node *p)
{
    int max = 0;
    if (p == 0)
    {
        return INT_MIN;
    }
    max = rmax(p->next);
    if (max > p->data)
        return max;
    else
        return p->data;
}

// recurrsive way to do linear search in linked list
struct node *rlinearSearch(struct node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (p->data == key)
        return p;
    return rlinearSearch(p->next, key);
}

void rReverseLink(struct node *q, struct node *p)
{
    if (p)
    {
        rReverseLink(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

// Below function are in iterative
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int count(struct node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int sum(struct node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int Max(struct node *p)
{
    int max = INT_MIN;
    while (p != NULL)
    {
        if (max < p->data)
            max = p->data;
        p = p->next;
    }
    return max;
}

// linear search
struct node *linearSearch(struct node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// Optimise linear search move to head appraoch
// linear search
struct node *optimiseLinearSearch(struct node *p, int key)
{
    struct node *q = NULL;

    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

// Inserting element in linked list
void insert(struct node *p, int index, int x)
{
    if (index < 0 || index > count(p))
        return;
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

void insert2(struct node *p, int index, int x)
{
    if (index < 0 || index > count(p))
        return;
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    if (index == 0)
    {
        t->next = second;
        second = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

// Insert a element in a sorted list in sorted manner
void sortedInsert(struct node *p, int x)
{
    struct node *t, *q = NULL;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
        first = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

// Deleting node from linked list
int deleteNode(struct node *p, int pos)
{
    struct node *q = NULL;
    int x = -1;
    // checking given position is valid or not
    if (pos < 1 || pos > count(p))
        return -1;
    // deleting first node
    if (pos == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    // deleting other node
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

// check linked list is sorted or not
int isSorted(struct node *p)
{
    int x = INT_MIN;
    while (p)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p->next = p->next;
    }
    return 1;
}

// Delete Duplicate element from linked list
void deleteDuplicate(struct node *p)
{
    struct node *q = p->next;
    while (q)
    {
        if (p->data != q->data)
        {
            p = q;
            q = p->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

// Reverse a linked list
// Reversing an element in Linked List
void reverseElement(struct node *p)
{
    int *a = (int *)malloc(sizeof(int) * count(p));
    struct node *q = p;
    int i = 0;
    while (q)
    {
        a[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q)
    {
        q->data = a[i];
        q = q->next;
        i--;
    }
}

// reverse link of linked list
void reverseLink(struct node *p)
{
    struct node *q = NULL, *r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// concatinating two linked list
void concat(struct node *p, struct node *q)
{
    third = p;
    while (p->next != NULL)
        p = p->next;
    p->next = q;
}

// merging two sorted linked list in sorted manner
void merginig(struct node *p, struct node *q)
{
    struct node *last = NULL;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
        last->next = p;
    if (q)
        last->next = q;
}

// checking linked list is a loop or linear
int isLoop(struct node *f)
{
    struct node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);
    if (p == q)
        return 1;
    else
        return 0;
}

int main()
{
    // create first linked list using create function
    // create second linked list using insert function
    struct node *t1, *t2;

    // creating first linked list
    int a[] = {3, 5, 16, 20, 34, 23, 12, 45};
    create(a, 8);
    // to insert in this list use insert(first,pos,x);

    // creating second linked list
    // insert2(second,0,3);
    // no other function has been created for second linked list

    // creating loop in linked list
    // t1 = first->next->next->next;
    // t2 = first->next->next->next->next->next->next->next;
    // t2->next = t1;

    return 0;
}