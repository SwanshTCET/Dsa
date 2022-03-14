#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>
class node
{
public:
    int top, size;
    char *a;
};
class Stack
{
    node *s1;

public:
    Stack(string s)
    {
        s1 = new node;
        s1->size = s.size();
        s1->top = -1;
        s1->a = new char;
    }
    void push(char x)
    {
        s1->top++;
        s1->a[s1->top] = x;
    }
    void pop()
    {
        s1->a[s1->top--];
    }
    bool isBalance(string c)
    {
        // iterating over string
        for (int i = 0; i < c.size(); i++)
        {
            if (c[i] == '(')
            {
                push(c[i]);
            }
            else if (c[i] == ')')
            {
                // top =-1 because we have initialized top with -1 so indexing is 0 based
                if (s1->top == -1)
                    return false;
                pop();
            }
        }
        if (s1->top == -1)
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