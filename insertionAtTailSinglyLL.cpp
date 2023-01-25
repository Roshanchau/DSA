#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
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

void deleteNode(int position, Node *&head)
{
    if (position == 1)
    {
        // deleting first node
        Node *temp = head;

        head = head->next;
        // memory free for start node
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any node and last node
        Node *prev;
        Node *curr = head;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
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

    deleteNode(6, head);
    display(head);

    return 0;
}