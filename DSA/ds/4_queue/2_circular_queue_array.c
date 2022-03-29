#include <stdio.h>
#include <stdlib.h>
#define nl printf("\n")

// defining structure of circular queue using array
struct Queue
{
    int size, front, rear, *Q;
};

// a function to create a circular queue with default value
void create(struct Queue *q, int size)
{
    q->size = size + 1;
    q->front = q->rear = 0;
    q->Q = (int *)malloc((q->size) * sizeof(int));
}

// a function to push element
void enqueue(struct Queue *q, int x)
{
    if (((q->rear + 1) % q->size) == q->front)
        printf("Queue is full \n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
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
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

// a function to display circular queue
void display(struct Queue q)
{
    int i = q.front + 1;
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != ((q.rear + 1) % q.size));
    nl;
}

int main()
{
    struct Queue q;
    create(&q, 5);
    return 0;
}