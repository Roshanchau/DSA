#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // creation of stack
    stack<int> s;

    // stack operation
    s.push(5);
    s.push(3);
    s.push(2);

    // pop
    s.pop();
    cout << "printing top element\t" << s.top() << endl;

    if (s.empty())
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        cout << "stack is not empty" << endl;
    }
    return 0;
}