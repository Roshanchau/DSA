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
    };
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAttail(Node *&tail , int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    Node *head = node1;
    Node *tail=node1;
    display(head);

    // insertAtHead(head, 12);
    // display(head);

    insertAttail(tail, 12);
    display(head);
    insertAttail(tail, 15);
    display(head);
    return 0;
}