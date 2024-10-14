#include <bits/stdc++.h>
using namespace std;

struct node {
    string name;
    vector<node*> children;

    node(string nameNode) : name(nameNode) {};
};

struct familyTree {
    node *root;
    unordered_map <string, node*> family; 

    node *getNode(string name){
        if (family.count(name) == 0){
            family[name] = new node(name);
        }
        return family[name];
    }

    void createFamily(string child, string parent){
        node *childNode = getNode(child);
        node *parentNode = getNode(parent);
        parentNode->children.push_back(childNode);
    }

    void descendants(node *parent, int &countD){
        countD += parent->children.size();
        for (node *child : parent->children){
            descendants(child, countD);
        }
    }

    int generations(node *parent){
        if (parent->children.size() == 0) return 0;
        int maxGen = 0;
        for (node *child : parent->children){
            maxGen = max(maxGen, 1+generations(child));
        }
        return maxGen;
    }
};

int main() {
    string child, parent;
    familyTree family;
    while (cin >> child){
        if (child == "***") break;
        cin >> parent;
        family.createFamily(child, parent);
    }
    string cmd, param;
    while (cin >> cmd){
        if (cmd == "***") break;
        cin >> param;
        if (cmd == "descendants"){
            int countD = 0;
            family.descendants(family.getNode(param), countD);
            cout << countD << endl;
        }
        if (cmd == "generation"){
            cout << family.generations(family.getNode(param)) << endl;
        }
    }
    return 0;
}