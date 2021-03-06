#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
int ilosc_krokow = 0;

struct Dictionary
{
    int key;
    int value;
};
struct Stack
{
    int top;
    unsigned capacity;
    struct Dictionary *array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (struct Dictionary *)malloc(stack->capacity * sizeof(struct Dictionary));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to add an item to stack.  It increases top by 1
void push(struct Stack *stack, struct Dictionary item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

// Function to remove an item from stack.  It decreases top by 1
struct Dictionary pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        struct Dictionary ret;
        ret.key = 0;
        ret.value = 0;
        return ret;
    }
    return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
struct Dictionary peek(struct Stack *stack)
{
    if (isEmpty(stack)){
        struct Dictionary ret;
        ret.key = 0;
        ret.value = 0;
        return ret;
    }
        
    return stack->array[stack->top];
}
struct Stack *stack;
int fibo(int n)
{
    struct Dictionary end;
    ilosc_krokow++;
    if (n == 0)
    {
        end.key = n;
        end.value = 0;
        push(stack, end);
        return 0;
    }
    else if (n == 1 || n == 2)
    {
        end.key = n;
        end.value = 1;
        push(stack, end);
        return 1;
    }
    int wynik = fibo(n - 2) + fibo(n - 1);
    end.key = n;
    end.value = wynik;
    push(stack, end);
    return wynik;
}
int main()
{
    stack = createStack(100);
    fibo(5);
    int i;
    for (i = 1; i <= ilosc_krokow; i++)
    {
        struct Dictionary print = pop(stack);
        printf("fibo%d(%d) = %d \n", i, print.key, print.value);
    }
}