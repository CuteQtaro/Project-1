#include <bits/stdc++.h>
using namespace std;

struct node
{
    int id;
    vector<node*> con;

    node(int idNode) : id(idNode) {};
};

struct cay{
    node *root;

    node makeRoot(int id)
    {
        node* tmp = new node(id);
        return *tmp;
    }

    node* findNode(node* currentNode, int targetId)
    {
        if (currentNode == nullptr) return nullptr;
        if (currentNode->id == targetId) return currentNode;
        for (node* child : currentNode->con){
            node* result = findNode(child, targetId);
            if (result != nullptr) return result;
        }
        return nullptr;
        
    }

    void insertNode(int childId, int dadId){
        node* dadNode = findNode(root, dadId);
        if (dadNode != nullptr && findNode(root, childId) == nullptr){
            dadNode->con.push_back(new node(childId));
        }
    }

    void postOrder (node* root){
        if (root == nullptr) return;
        for (node* child : root->con){
            postOrder(child);
        }
        cout << root->id << " ";
    }

    void preOrder (node* root){
        if (root == nullptr) return;
        cout << root->id << " ";
        for (node* child : root->con){
            preOrder(child);
        }
    }

    void inOrder (node* root){
        if (root == nullptr) return;
        if (!root->con.empty()){
            inOrder(root->con.front()); // first child
        }
        cout << root->id << " ";
        int length = root->con.size(); // number of children
        for (int i = 1; i < length; i++){
            inOrder(root->con[i]);
        }
    }
};

int main()
{
    string s;
    cay c;
    while (true){
        cin >> s;
        if (s == "*") break;
        if (s == "MakeRoot"){
            int id;
            cin >> id;
            c.root = new node(id);
        }
        else if (s == "Insert"){
            int childId, dadId;
            cin >> childId >> dadId;
            c.insertNode(childId, dadId);
        }
        else if (s == "PostOrder"){
            c.postOrder(c.root);
            cout << endl;
        }
        else if (s == "PreOrder"){
            c.preOrder(c.root);
            cout << endl;
        }
        else if (s == "InOrder"){
            c.inOrder(c.root);
            cout << endl;
        }
    }
}
