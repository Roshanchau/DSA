#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int rear;
    int front;
    int *Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new int[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }
    void enqueue(int data);
    int dequeue();
    void display();
};

void Queue::enqueue(int data)
{
    if (rear == size - 1)
    {
        cout << "Queue overflow" << endl;
    }
    else
    {
        rear++;
        Q[rear] = data;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if (front == rear)
    {
        cout << "queue is empty" << endl;
    }
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

void Queue::display()
{
    for (int i = front + 1; i <= rear; i++)
    {
        cout << Q[i] << " ";
    }
    cout << endl;
}
int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(1);

    q.display();

    cout << "deleted: " << q.dequeue() << endl;
    q.display();

    cout << "deleted: " << q.dequeue() << endl;
    q.display();

    cout << "deleted: " << q.dequeue() << endl;
    q.display();

    cout << "deleted: " << q.dequeue() << endl;
    q.display();

    return 0;
}