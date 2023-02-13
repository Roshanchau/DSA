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
        front = rear = 0;
        size = 10;
        Q = new int[size];
    }
    Queue(int size)
    {
        front = rear = 0;
        this->size = size;
        Q = new int[this->size];
    }
    void enqueue(int data);
    int dequeue();
    void display();
};

void Queue::enqueue(int data)
{
    if ((rear + 1) % size == front)
    {
        cout << "Queue overflow" << endl;
    }
    else
    {
        rear = (rear + 1) % size;
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
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

void Queue::display()
{
    int i = (front + 1) % size;
    do
    {
        cout << Q[i] << " ";
        i = (i + 1) % size;
    } while (i != ((rear + 1) % size));
    cout << endl;
}
int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(2);
    // q.enqueue(1);

    q.display();

    cout << "deleted: " << q.dequeue() << endl;
    q.display();

    cout << "deleted: " << q.dequeue() << endl;
    q.display();

    cout << "deleted: " << q.dequeue() << endl;
    q.display();

    cout << "deleted: " << q.dequeue() << endl;
    q.enqueue(9);
    q.enqueue(15);
    q.enqueue(1);
    q.display();

    return 0;
}