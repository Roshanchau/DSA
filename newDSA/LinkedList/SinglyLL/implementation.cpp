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

// insertion at head
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

// insertion at tail
void insertAttail(Node *&tail , int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}

// insertion at middle
void insertAtmiddle(Node *&head , int pos , int d){
    Node *temp=head;
    int cnt=1;
    while(cnt< pos-1){
        temp=temp->next;
        cnt++;
    }

    Node * newNode= new Node(d);
    newNode->next=temp->next;
    temp->next=newNode;
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
    insertAttail(tail, 20);
    display(head);
    insertAttail(tail, 30);
    display(head);
    insertAtmiddle(head, 4, 17);
    display(head);
    return 0;
}