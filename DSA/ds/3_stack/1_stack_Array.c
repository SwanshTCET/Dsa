#include <stdio.h>
#include <stdlib.h>

// Defining strcuture of stack
struct stack
{
    int top, size;
    int *a;
};

// creating empty stack
void create(struct stack *st)
{
    printf("Enter Size : ");
    scanf("%d", &st->size);
    st->top = -1;
    st->a = (int *)malloc(sizeof(int) * st->size);
}

// display stack
void display(struct stack st)
{
    for (int i = st.top; i >= 0; i--)
        printf("%d ", st.a[i]);
    printf("\n");
}

// checking stack is full or not
int isFull(struct stack *st)
{
    if (st->top == st->size - 1)
        return 1;
    return 0;
}

// checking stack is empty or not
int isEmpty(struct stack *st)
{
    if (st->top == -1)
        return 1;
    return 0;
}

// peek giving element at that index
int peek(struct stack st, int index)
{
    int x = -1;
    if (st.top - index < 0)
        printf("Invalid Index \n");
    else
        x = st.a[st.top - index + 1];
    return x;
}

// stacktop element present at top
int stacktop(struct stack st)
{
    if (isEmpty)
        return -1;
    return st.a[st.top];
}

// push
void push(struct stack *st, int x)
{
    if (isFull(st))
    {
        printf("Stack Overflow  \n");
        printf("%d is not inserted \n", x);
    }
    else
    {
        st->top++;
        st->a[st->top] = x;
    }
}

// pop
int pop(struct stack *st)
{
    int x = -1;
    if (isEmpty(st))
        printf("Stack Underflow \n");
    else
    {
        x = st->a[st->top--];
    }
    return x;
}

int main()
{
    struct stack st;
    create(&st);
    display(st);
    return 0;
}