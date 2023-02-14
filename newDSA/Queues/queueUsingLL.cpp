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
        cout << "memory is free with value" << val << endl;
    }
};
Node *front, *rear = NULL;
void enqueue(int a)
{
    Node *temp = new Node(a);
    if (temp == NULL)
    {
        cout << "Queue is full" << endl;
    }

    else
    {
        if (front == NULL)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
}

int dequeue()
{
    int x = -1;
    Node *p;
    if (front == NULL)
    {
        cout << "queue is empty" << endl;
    }
    else
    {
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}

void display()
{
    Node *temp = front;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != NULL);
    cout
        << endl;
}
int main()
{
    enqueue(10);
    enqueue(5);
    enqueue(9);
    enqueue(9);
    enqueue(7);

    display();

    cout << "deleted: " << dequeue() << endl;
    display();
    return 0;
}