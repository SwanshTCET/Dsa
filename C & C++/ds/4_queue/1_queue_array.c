#include <stdio.h>
#include <stdlib.h>
#define nl printf("\n")

// defining structure of queue using array
struct Queue
{
    int size, front, rear, *Q;
};

// a function to create a queue with default value
void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc((q->size) * sizeof(int));
}

// a function to push element
void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
        printf("Queue is full \n");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

// a function to delete element
int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("Queue is empty\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

// a function to display queue
void display(struct Queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
        printf("%d ", q.Q[i]);
    nl;
}

int main()
{
    struct Queue q;
    create(&q, 5);
    return 0;
}