#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<ll>

class Queue
{
private:
    int size, front, rear, *Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new int[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::enqueue(int x)
{
    if (rear == size - 1)
        cout << "Queue is full" << endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if (rear == front)
        cout << "Queue is Empty" << endl;
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}

void Queue::display()
{
    for (int i = front + 1; i <= rear; i++)
        cout << Q[i] << " ";
    cout << endl;
}

int main()
{
    Queue q(5);
    return 0;
}