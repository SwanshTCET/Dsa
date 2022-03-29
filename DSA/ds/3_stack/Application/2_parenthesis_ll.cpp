#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>
class node
{
public:
    char data;
    struct node *next;
};
class Stack
{
    node *s1;

public:
    Stack(string s)
    {
        s1 = new node;
        s1=NULL;
    }
    void push(char x)
    {
        node *t;
        t = new node;
        if (t == NULL)
            printf("Heap is full / stack overflow \n");
        else
        {
            t->data = x;
            t->next = s1;
            s1 = t;
        }
    }
    void pop()
    {
        if (s1 == NULL)
            printf("Stack Underflow\n");
        else
        {
            struct node *t;
            t = s1;
            s1 = s1->next;
            delete t;
        }
    }
    bool isBalance(string c)
    {
        for (int i = 0; i < c.size(); i++)
        {
            // cout<<i<< " "<<c[i]<<endl;
            if (c[i] == '(')
            {
                push(c[i]);
            }
            else if (c[i] == ')')
            {
                if (s1 == NULL)
                    return false;
                pop();
            }
        }
        if (s1 == NULL)
            return true;
        else
            return false;
    }
};
int main()
{
    string s;
    cout << "Enter string/expression" << endl;
    cin >> s;
    Stack sa(s);
    if (sa.isBalance(s))
        cout << "Proper Expression" << endl;
    else
        cout << "Improper Expression" << endl;

    return 0;
}