#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int lengthOfLL(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node *&head, int a)
{
    Node *temp = new Node(a);
    if (head != NULL)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node *&head, int a)
{
    Node *last;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    last = temp;
    Node *newNode = new Node(a);
    last->next = newNode;
    newNode->prev = last;
    last = newNode;
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    print(head);

    insertAtHead(head, 11);
    print(head);

    insertAtTail(head, 20);
    print(head);

    insertAtHead(head, 4);
    print(head);

    insertAtTail(head, 6);
    print(head);

    cout << lengthOfLL(head) << endl;

    return 0;
}