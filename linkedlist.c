#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    int info;
    struct node *next;
};
struct node *head = NULL, *ptr, *newptr;
struct node *getnode()
{
    struct node *np;
    np = (struct node *)malloc(sizeof(struct node));
    printf("Enter a data: ");
    scanf("%d", &np->info);
    np->next = NULL;
    return np;
}
void create()
{
    struct node *last;
    char choice;
    do
    {
        newptr = getnode();
        if (head == NULL)
            head = newptr;
        else
            last->next = newptr;
        last = newptr;
        printf("Do you want to continue (Y or N): ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');
    printf("LL Creation Successfull");
}
void insertLL()
{
    int choice;
    printf("1.Front\n2.Last\n3.Anywhere::");
    scanf("%d", &choice);
    if (choice == 1)
    {
        newptr = getnode();
        newptr->next = head;
        head = newptr;
        printf("Insertion at front Successfull:");
    }
}
void deleteLL()
{
}
void display()
{
    ptr = head;
    printf("The data are::\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
}
int main()
{
    int choice;
    create();
    getch();
    while (1)
    {
        system("cls");
        printf("***Linked List***");
        printf("Enter a choice\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertLL();
            break;
        case 2:
            deleteLL();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Input\n");
        }
        getch();
    }
    return 0;
}
