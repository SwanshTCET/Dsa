#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>

class node
{
public:
    int data;
    node *next;
};

class linkedList
{
    node *first;

public:
    linkedList() { first = NULL; }
    linkedList(int a[], int n);
    ~linkedList();

    void display();
    int length();
    void insert(int index, int x);
    int Delete(int index);
};

linkedList::linkedList(int a[], int n)
{
    node *last, *t;
    first = new node;
    int i = 0;
    first->data = a[i];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

linkedList::~linkedList()
{
    node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void linkedList::display()
{
    node *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int linkedList ::length()
{
    node *p = first;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void linkedList::insert(int index, int x)
{
    node *t, *p = first;
    if (index < 0 || index > length())
        return;
    t = new node;
    t->data = x;
    t->next = NULL;
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

int linkedList::Delete(int index)
{
    node *p, *q = NULL;
    int x = -1;
    if (index < 1 || index > length())
        return x;
    if (index == 1)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        p = first;
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}
int main()
{
    int a[] = {1, 3, 4, 5, 6, 7, 8, 9};
    linkedList l(a, 8);
    l.display();
    return 0;
}