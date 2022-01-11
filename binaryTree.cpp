#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->right = newNode->left = NULL;
    return newNode;
}

Node *insert(Node *root, int data)
{
    //first create a new node and link it with root pointer
    //we are using recursion so that every time the root become null due to recurssion a new Node will be created
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data <= root->data)
    {
        /*root left = insert(NULL,data) as left of newly Created Node is NULL
            and with the help of this null we create a newNode by using root == root->next(NULL)
            we can also do it by no recursive way but i don't know how to implement now maybe in future
            the equal sign shows that the same data goes left
        */
        root->left = insert(root->left, data); //and insert(NULL, data) will become a newNode and right->left will point towards this newly created Node
    }
    else
    {
        root->right = insert(root->right, data); //insert(root->right, data) consider this as a newly created node
    }

    //this return original value of root pointer which is the rootNode address(the address root pointer is storing)
    return root;
}

//this function is used to search certain element using recursion
bool search(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    //search the data of every left Node's element of every previous Node
    else if (data <= root->data)
    {
        return search(root->left, data);
    }
    //search the data of every right Node's element of every previous Node
    else
    {
        return search(root->right, data);
    }
}

//this function is used to find min and max value in the tree
int findMin(Node *root)
{
    Node *current = root;
    if (root == NULL)
    {
        cout << "Error!" << endl;
        return -1;
    }
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current->data;
}
int findMax(Node *root)
{
    Node *current = root;
    if (root == NULL)
    {
        cout << "Error!" << endl;
        return -1;
    }
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current->data;
}

//this function is used to get height of the tree
int height(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    if (lHeight > rHeight)
    {
        return (lHeight + 1);
    }
    else
    {
        return (rHeight + 1);
    }
}

/*
    Traversal
    Time complexity O(n)
    Space Complexity O(h) : height
        worst case : O(n)
        best case  : O(logn)
*/

// Traversal preorder
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
// Traversal Inorder : This traversal used to sort data :)
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
// Traversal postorder
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
// Print all the left nodes of a root
void lessvalue(Node *root, int key)
{
    if (root == NULL)
    {
        return;
    }
    lessvalue(root->left, key);
    if (root->data < key)
    {
        cout << root->data << " ";
        lessvalue(root->right, key);
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 40);
    insert(root, 20);
    insert(root, 15);
    insert(root, 30);
    insert(root, 25);
    insert(root, 24);
    insert(root, 35);
    insert(root, 50);
    insert(root, 45);
    cout << "Height :" << height(root) << endl;
    // preorder(root);
    inorder(root);
    // postorder(root);
    // lessvalue(root, root->data);

    return 0;
}