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
        front = rear = 0;
        this->size = size + 1;
        Q = new int[this->size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::enqueue(int x)
{
    if ((rear + 1) % size == front)
        cout << "Queue is full" << endl;
    else
    {
        rear = (rear + 1) % size;
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
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

void Queue::display()
{
    int i = front + 1;
    do
    {
        cout << Q[i] << " ";
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
    cout << endl;
}

int main()
{
    Queue q(4);
    return 0;
}