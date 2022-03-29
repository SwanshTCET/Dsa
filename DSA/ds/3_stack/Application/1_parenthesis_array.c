#include <stdio.h>
#include <stdlib.h>

// Structure of stack for parenthesis matching
struct stack
{
    int top, size;
    char *a;
};

// creating empty stack
void create(struct stack *st)
{
    printf("Enter size of a string : ");
    scanf("%d", &st->size);
    st->top = -1;
    st->a = (char *)malloc(sizeof(char) * st->size);
}

// will push '(' bracket in stack
void push(struct stack *st, char x)
{
    st->top++;
    st->a[st->top] = x;
}

// will pop ')' bracket in stack
void pop(struct stack *st)
{
    st->a[st->top--];
}

// checking equal number of opening and closing bracket are there or not
int isBalance(struct stack *st, char c[])
{
    // iterating over string
    for (int i = 0; i < st->size; i++)
    {
        char s = c[i];
        if (s == '(')
        {
            push(st, s);
        }
        else if (s == ')')
        {
            // top =-1 because we have initialized top with -1 so indexing is 0 based
            if (st->top == -1)
            {
                return 0;
            }
            pop(st);
        }
    }
    if (st->top == -1)
        return 1;
    else
        return 0;
}
int main()
{
    struct stack st;
    create(&st);
    char c[st.size];
    printf("Enter a expression \n");
    scanf("%s", c);
    printf("%d", isBalance(&st, c));
    return 0;
}