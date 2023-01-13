#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void insertionAtTail(Node *&tail, int a)
{
    Node *temp = new Node(a);
    tail->next = temp;
    tail = temp;
}
void insertionAtMiddle(Node *head, int pos, int c)
{
    Node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    Node *insertAtMiddle = new Node(c);
    insertAtMiddle->next = temp->next;
    temp->next = insertAtMiddle;
}
void display(Node *&head)
{
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
    cout << endl;
}
int main()
{
    // creating a new node.
    Node *node1 = new Node(10);

    // pointing head to the node1
    Node *head = node1;
    // pointing tail to the node1
    Node *tail = node1;

    insertionAtTail(tail, 20);
    display(head);
    insertionAtTail(tail, 25);
    display(head);

    insertionAtMiddle(head, 3, 33);
    display(head);
    insertionAtTail(tail, 30);
    display(head);
    insertionAtTail(tail, 35);
    display(head);
    return 0;
}