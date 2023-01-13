#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    // creating first node using malloc function.
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    // creating rest of the node by scanning through the array.
    for (i = 1; i <= n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        // while creating a node always remember to assign the data and the next.
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// iterative display(traversing) of LL

// void display(struct Node *p)
// {
//     while (p != NULL)
//     {
//         printf("%d\t", p->data);
//         p = p->next;
//     }
// }

// recursive display(traversing) of LL

void Rdisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d\t", p->data);
        Rdisplay(p->next);
        // printf("%d\t", p->data); ----> results in reverse display of the nodes data of a LL.
    }
}

int main()
{
    int A[] = {3, 4, 5, 3, 12, 2};
    create(A, 6);

    Rdisplay(first);
    return 0;
}