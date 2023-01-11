#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertionAtHead(Node *&head, int d)
{
    // new temp node
    Node *temp = new Node(d);
    temp->next = head;
    // head pointing back to temp node.
    head = temp;
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
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    // head pointer to node1
    Node *head = node1;
    insertionAtHead(head, 20);
    print(head);
    insertionAtHead(head, 15);
    print(head);
    return 0;
}