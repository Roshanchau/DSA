#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int a)
    {
        this->data = a;
        this->next = NULL;
    }
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
void push(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
int pop(Node *&head)
{
    if (head == NULL)
    {
        cout << "stack underflow" << endl;
        return -1;
    }
    else
    {
        Node *temp = head;
        int x = temp->data;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return x;
    }
}

int peek(Node *&head)
{
    if (head != NULL)
    {
        return head->data;
    }
    else
    {
        cout << "stack is empty" << endl;
        return -1;
    }
}

bool isEmpty(Node *&head)
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void print(Node *&head)
{
    // temp node pointing back to the head as it is the starting node and needs to be addressed again in this function as this is a diff scope
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    push(head, 20);
    push(head, 30);
    print(head);

    cout << pop(head) << endl;
    cout << endl;
    print(head);

    cout << pop(head) << endl;
    cout << endl;
    print(head);

    cout << pop(head) << endl;
    cout << endl;
    print(head);

    cout << pop(head) << endl;
    cout << endl;
    print(head);

    push(head, 40);
    print(head);
    push(head, 50);
    print(head);
    push(head, 60);
    print(head);

    cout << pop(head) << endl;
    cout << endl;
    print(head);

    cout << peek(head) << endl
         << endl;

    cout << pop(head) << endl;
    cout << endl;
    print(head);
    cout << pop(head) << endl;
    cout << endl;
    print(head);

    push(head, 90);
    print(head);

    if (isEmpty(head))
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        cout << "stack is not empty" << endl;
    }

    return 0;
}