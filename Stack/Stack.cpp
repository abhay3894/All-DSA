#include <bits/stdc++.h>

using namespace std;

class Stack
{
public:
    int arr[5];
    int front;
    int rear;
    Stack()
    {
        front = -1;
        rear = -1;
    }
    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }
    void push(int value)
    {
        if (isEmpty())
        {
            front = 0;
            rear = 0;
            arr[front] = value;
        }
        else
        {
            rear++;
            arr[rear] = value;
        }
    }
    void pop()
    {
        cout << arr[rear] << " "
             << "Removed" << endl;
        arr[rear] = 0;
        rear--;
    }

    void peek()
    {
        cout << arr[rear] << endl;
    }

    void traverse()
    {
        if (isEmpty())
        {
            cout << "Nothing to traverse" << endl;
        } 
        else
        {
            for (int i = rear; i >= front; i--)
            {
                cout << arr[i] << endl;
            }
        }
    }
};

int main()
{
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    // stack.pop();
    stack.peek();
    stack.traverse();

    return 0;
}