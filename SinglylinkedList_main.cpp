#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

Node *push(Node *head, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
    }
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return head;
}

Node *append(Node *head, int data)
{
    Node *current = head;
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

Node *reverse(Node *head)
{
    Node *current = head;
    Node *front = NULL;
    Node *prev = NULL;
    while (current != NULL)
    {
        *front = current->next;
        current->next = prev;
        prev = current;
        current = front;
    }
    head = prev;
    return head;
}

void reversePrint(Node *head)
{
    Node *current = head;
    stack<int> rev;
    if (head == NULL)
    {
        return;
    }
    while (current != NULL)
    {
        rev.push(current->data);
        current = current->next;
    }
    cout << " \n";
    while (!rev.empty())
    {
        cout << rev.top() << " ";
        rev.pop();
    }
}

Node *recReverse(Node *head)
{
    if (head->next == NULL || head == NULL)
    {
        return head;
    }
    Node *ref = recReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return ref;
}

void traverse(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";
    traverse(head->next);
}

int main()
{
    Node *head = NULL;
    head = append(head, 10);
    head = append(head, 20);
    head = append(head, 30);
    head = append(head, 40);
    head = append(head, 50);
    // head = push(head, 6);
    // head = push(head, 5);
    // head = push(head, 4);
    // head = push(head, 3);
    traverse(head);
    head = reverse(head);
    // head = recReverse(head);
    cout << "\n";
    traverse(head);

    return 0;
}