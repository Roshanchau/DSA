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
        int val = this->data;
        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }

        cout << "memoery is free with data" << val << endl;
    }
};

void insertNode(Node *&tail, int element, int data)
{
    // for empty node
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }

    // assuming there exists an element in the LL
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node *&tail, int element)
{
    if (tail == NULL)
    {
        cout << "LL is empty" << endl;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        // 1 node in linked list
        if (curr == prev)
        {
            tail = NULL;
        }

        //>=2 linked list
        if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

// traversal in cricular LL
void display(Node *&tail)
{

    if (tail == NULL)
    {
        cout << "linked list is empty." << endl;
    }
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}
int main()
{
    Node *tail = NULL;
    insertNode(tail, 3, 5);
    display(tail);
    insertNode(tail, 5, 15);
    display(tail);
    // insertNode(tail, 5, 10);
    // display(tail);
    // insertNode(tail, 10, 7);
    // display(tail);
    // insertNode(tail, 15, 2);
    // display(tail);

    // cout << tail->data << endl;
    deleteNode(tail, 5);
    display(tail);

    return 0;
}