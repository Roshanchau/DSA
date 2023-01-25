#include <stdio.h>
#include <stdlib.h>
#define size 5
struct stack
{
    int data[size];
    int top;
};
void push(struct stack *s)
{
    if (s->top == size - 1)
        printf("Stack Overflow\n");
    else
    {
        ++(s->top);
        printf("Enter the data");
        scanf("%d", &s->data[s->top]);
    }
}
void pop(struct stack *s)
{
    if (s->top == -1)
        printf("Stack is Empty");
    else
    {
        printf("%d is popped\n", s->data[s->top]);
        --(s->top);
    }
}
void display(struct stack s)
{
    int i;
    if (s.top == -1)
        printf("Stack is Empty");
    else
    {
        printf("The elements are\n");
        for (i = s.top; i >= 0; i--)
            printf("%d\n", s.data[i]);
    }
}
int main()
{
    struct stack s;
    int choice;
    s.top = -1;

    while (1)
    {
        system("cls");

        printf("Stack\n1.PUSH\n2.POP\n3.Display\n4.Exit\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(&s);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            display(s);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
        getch();
    }
}