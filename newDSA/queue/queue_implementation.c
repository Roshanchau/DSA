#include <stdio.h>
#include <stdlib.h>
#define size 5
struct queue
{
    int data[size];
    int front, rear;
};
void enqueue(struct queue *q)
{

    if (q->rear == size - 1)
        printf("Queue is full\n");
    else
    {
        ++(q->rear);
        printf("Enter the data");
        scanf("%d", &q->data[q->rear]);
    }
}
void dequeue(struct queue *q)
{
    if (q->rear < q->front)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("%d is Dequeue\n", q->data[q->front]);
        ++(q->front);
    }
}
void display(struct queue q)
{
    int i;
    if (q.rear < q.front)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The elements are\n");
        for (i = q.front; i <= q.rear; i++)
            printf("%d\t", q.data[i]);
    }
}
void front(struct queue *q)
{
    if (q->rear < q->front)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The value of front is %d", q->data[q->front]);
    }
}
void makeempty(struct queue *q)
{
    q->front = 0;
    q->rear = -1;
}
int main()
{
    struct queue q;
    q.front = 0;
    q.rear = -1;
    int choice;
    q.rear = -1;
    while (1)
    {
        system("cls");
        printf("Queue\n1.ENQUEUE\n2.DEQUEUE\n3.Display\n4.MAKEEMPTY\n5.EXIT\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue(&q);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(q);
            break;
        case 4:
            makeempty(&q);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
        getch();
    }
}