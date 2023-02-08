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

void insertAtHead(Node *&head, Node *&tail, int a)
{
    if (head != NULL)
    {
        Node *temp = new Node(a);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(a);
        head = temp;
        tail = temp;
    }
}
void insertAtTail(Node *&tail, Node *&head, int a)
{

    if (tail != NULL)
    {
        Node *newNode = new Node(a);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else
    {
        Node *temp = new Node(a);
        tail = temp;
        head = temp;
    }
}

void insertAtPos(Node *&tail, Node *&head, int pos, int z)
{
    Node *temp = head;

    if (pos == 1)
    {
        insertAtHead(head, tail, z);
        return;
    }
    int cnt = 1;
    while (cnt < pos - 1) //-> we have to acess the node before the curr node in the given pos.
    {
        temp = temp->next;
        cout << temp->data << endl;
        cnt++; // increased the cnt by1;
        cout << "count=" << cnt << endl;
    }
    if (temp->next == NULL)
    {
        cout << temp->next << endl;

        insertAtTail(tail, head, z);
        return;
    }
    Node *nodeToInsert = new Node(z);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
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
        temp->next->prev = NULL;
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
        curr->next->prev = prev;
        curr->prev = NULL;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);

    insertAtHead(head, tail, 11);
    print(head);

    insertAtTail(tail, head, 20);
    print(head);

    insertAtHead(head, tail, 4);
    print(head);

    insertAtTail(tail, head, 6);
    print(head);

    insertAtPos(tail, head, 6, 33);
    print(head);

    deleteNode(2, head);
    print(head);
    deleteNode(4, head);
    print(head);
    cout << lengthOfLL(head) << endl;

    return 0;
}