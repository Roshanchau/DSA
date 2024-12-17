#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    // destructor
    ~Node()
    {
        int val = this->data;
        if (this->next != NULL || this->prev != NULL)
        {
            delete next;
            this->next = NULL;
            delete prev;
            this->prev = NULL;
        }
        cout << "mem is free with data" << val << endl;
    }
};

/*      Insertion           */

// insertion at head
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);

    temp->next = head;
    temp->prev = NULL;
    head->prev = temp;
    head = temp;
}

// insertion at tail
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);

    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

// insertion at a position
void insertATpos(Node *&head, Node *&tail, int pos, int d)
{
    Node *temp = new Node(d);

    // insert at head
    if (pos == 1)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
        return;
    }

    // elsewhere
    int i = 1;
    Node *curr = head;
    while (i < pos - 1)
    {
        curr = curr->next;
        i++;
    }

    // at tail
    if (curr->next == NULL)
    {
        curr->next = temp;
        temp->prev = curr;
        tail = temp;
        return;
    }

    Node *nextNode = curr->next;
    nextNode->prev = temp;
    temp->next = nextNode;
    curr->next = temp;
    temp->prev = curr;
}

/*        deletion        */

// deletion at head
void deleteAthead(Node *&head)
{
    Node *temp = head;
    Node *nextNode = temp->next;

    head = temp->next;
    temp->next = NULL;
    nextNode->prev = NULL;
    delete temp;
}

// deletion at tail
void deleteAtTail(Node *&tail)
{
    Node *temp = tail;
    tail = temp->prev;
    tail->next = NULL;
    temp->prev = NULL;
    delete temp;
}

// deletion at position
void deleteAtPos(Node *&head, Node *&tail, int pos)
{
    // delete at head
    if (pos == 1)
    {
        Node *temp = head;
        Node *nextNode = temp->next;

        head = temp->next;
        temp->next = NULL;
        nextNode->prev = NULL;
        delete temp;
        return;
    }

    // elsewhere
    int i=1;
    Node*prev=head;
    while(i<pos-1){
        prev=prev->next;
        i++;
    }
    Node*curr=prev->next;
    // if pos is  at tail
    if(curr->next==NULL){
        prev->next=NULL;
        curr->prev=NULL;
        delete curr;
        tail=prev;
        return;
    }
    Node*nextNode=curr->next;
    prev->next=curr->next;
    nextNode->prev=curr->prev;
    curr->prev=NULL;
    curr->next=NULL;
    delete curr;
}

// TRAVERSAL IN DOUBLY LL

// type 1: froward traversal
void forwardTraverse(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// type2: backward traversal
void backwardTraverse(Node *&tail)
{
    Node *curr = tail;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    // insertAtHead(head , 20);
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertATpos(head, tail, 1, 90);
    forwardTraverse(head);
    // deleteAthead(head);
    // deleteAtTail(tail);
    deleteAtPos(head, tail , 6);
    forwardTraverse(head);
    backwardTraverse(tail);
    return 0;
}