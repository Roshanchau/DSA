#include <iostream>
using namespace std;

class stack
{
    // properties
public:
    int size;
    int *arr;
    int top;

    stack(int a)
    {
        this->size = a;
        this->top = -1;
        this->arr = new int(size);
    }

    // behaviour
    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "stack overflow" << endl;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "stack underflow" << endl;
        }
        else
        {
            top--;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "stack is empty" << endl;
            return -1;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    stack s(5);
    s.push(34);
    s.push(40);
    s.push(35);
    s.push(10);
    s.push(17);
    cout << "The top element is \t" << s.peek() << endl;

    s.pop();
    cout << "The top element is \t" << s.peek() << endl;
    s.pop();
    cout << "The top element is \t" << s.peek() << endl;
    s.pop();
    cout << "The top element is \t" << s.peek() << endl;
    s.pop();
    cout << "The top element is \t" << s.peek() << endl;
    s.pop();
    cout << "The top element is \t" << s.peek() << endl;

    if (s.isEmpty())
    {
        cout << "stack is empty";
    }
    else
    {
        cout << "stack is not empty";
    }
    return 0;
}