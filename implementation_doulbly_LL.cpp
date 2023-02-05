#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
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
    else
    {
        return;
    }
}
void insertAtTail(Node *&tail, int a)
{
    Node *newNode = new Node(a);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertAtPos(Node *&tail, Node *&head, int pos, int z)
{
    Node *temp = head;

    if (pos == 1)
    {
        insertAtHead(head, z);
        return;
    }
    int cnt = 1;
    while (cnt < pos - 1) //-> we have to acess the node before the curr node in the given pos.
    {
        temp = temp->next;
        cnt++; // increased the cnt by1;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, z);
        return;
    }
    Node *nodeToInsert = new Node(z);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);

    insertAtHead(head, 11);
    print(head);

    insertAtTail(tail, 20);
    print(head);

    insertAtHead(head, 4);
    print(head);

    insertAtTail(tail, 6);
    print(head);

    insertAtPos(tail, head, 5, 33);
    print(head);

    cout << lengthOfLL(head) << endl;

    return 0;
}