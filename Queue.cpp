#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Queue
{
    int arr[5];
    int front;
    int rear;
    Queue()
    {
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    void enqueue(int val)
    {
        if (rear > 4)
        {
            cout << "Queue is full" << endl;
        }
        else if (rear == -1 && front == -1)
        {
            front++;
            rear++;
        }
    }
    void dequeue()
    {
        if (rear == -1 && front == -1)
        {
            cout << "Queue is Empty!" << endl;
        }
        else if (front == rear)
        {
            cout << arr[front] << endl;
            front = rear = -1;
        }
    }
    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{

    return 0;
}