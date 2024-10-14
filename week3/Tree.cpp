#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *firstChild;
    Node *rightSibling;
};

Node *root = NULL;

void makeRoot(int x)
{
    root = new Node;
    root->data = x;
    root->firstChild = NULL;
    root->rightSibling = NULL;
}

bool isExist(Node *root, int x)
{
    if (root == NULL)
        return false;
    if (root->data == x)
        return true;
    return isExist(root->firstChild, x) || isExist(root->rightSibling, x);
}

Node *find(Node *root, int x)
{
    if (root == NULL)
        return NULL;
    if (root->data == x)
        return root;
    Node *temp = find(root->firstChild, x);
    if (temp != NULL)
        return temp;
    return find(root->rightSibling, x);
}

void insert (Node *root, int u, int v){ // insert u as the last child of v, if v is not exist, do nothing
    if (isExist(root, v) == true && isExist(root, u) == false){
        Node *temp = find(root, v);
        Node *newNode = new Node;
        newNode->data = u;
        newNode->firstChild = NULL;
        newNode->rightSibling = NULL;
        if (temp->firstChild == NULL){
            temp->firstChild = newNode;
        } else {
            Node *temp2 = temp->firstChild;
            while (temp2->rightSibling != NULL){
                temp2 = temp2->rightSibling;
            }
            temp2->rightSibling = newNode;
        }
    }
}

void preOrder(Node *root){
    if (root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->firstChild);
    preOrder(root->rightSibling);
}

void postOrder(Node *root){
    if (root == NULL){
        return;
    }
    postOrder(root->firstChild);
    postOrder(root->rightSibling);
    cout << root->data << " ";
}

void inOrder(Node *root){
    if (root == NULL){
        return;
    }
    inOrder(root->firstChild);
    cout << root->data << " ";
    inOrder(root->rightSibling);
}

int main()
{
    string s;
    while (true)
    {
        cin >> s;
        if (s == "MakeRoot")
        {
            int x;
            cin >> x;
            makeRoot(x);
        }
        if (s == "Insert")
        {
            int u, v;
            cin >> u >> v;
            insert(root, u, v);
        }
        if (s == "PreOrder")
        {
            preOrder(root);
            cout << endl;
        }
        if (s == "PostOrder")
        {
            postOrder(root);
            cout << endl;
        }
        if (s == "InOrder")
        {
            inOrder(root);
            cout << endl;
        }
        if (s == "*")
        {
            break;
        }
    }
    return 0;
}