#include <bits/stdc++.h> 
using namespace std;

void addlast(list<int> &l, int x) { 
    if (l.empty()) {
        l.push_back(x);
        return;
    }
    list<int>::iterator it = l.begin();
    while (it != l.end()) { 
        if (*it == x) {
            break;
        }
        it++;
    }
    if (it == l.end()) {
        l.push_back(x);
    }
    
}   

void addfirst(list<int> &l, int x) {
    if (l.empty()) {
        l.push_front(x);
        return;
    }
    list<int>::iterator it = l.begin();
    while (it != l.end()) {
        if (*it == x) { 
            break;
        }
        it++;
    }
    if (it == l.end()) { 
    l.push_front(x);
    }
}

void addafter(list<int> &l, int x, int y) { 
    list<int>::iterator it = l.begin();
    while (it != l.end()) {
        if (*it == y) {
            it++;
            list<int>::iterator it1 = it;
            while (it != l.end()) {
                if (*it == x) {
                    break;
                }
                it++;
            }
            if (it == l.end()) { 
                l.insert(it1, x);
            }
        }
        it++;
    }
    
}

void addbefore(list<int> &l, int x, int y) { 
    list<int>::iterator it = l.begin();
    while (it != l.end()) {
        if (*it == y) {
            list<int>::iterator it1 = it;
            while (it != l.begin()) {
                it--;
                if (*it == x) {
                    break;
                }
            }
            if (it == l.begin()) {
                l.insert(it1, x);
            }
            break;
        }
        it++;
    }
    
}

void remove(list<int> &l, int x) {
    list<int>::iterator it = l.begin();
    while (it != l.end()) {
        if (*it == x) {
            l.erase(it);
            break;
        }
        it++;
    }
}

void reverse(list<int> &l) {
    l.reverse();
}

int main() 
{ 
    int n;
    cin >> n;
    list<int> l;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        l.push_back(x);
    }
    string cmd;
    while (cin >> cmd) {
        if (cmd == "addlast") {
            int x;
            cin >> x;
            addlast(l, x);
        } else if (cmd == "addfirst") {
            int x;
            cin >> x;
            addfirst(l, x);
        } else if (cmd == "addafter") {
            int x, y;
            cin >> x >> y;
            addafter(l, x, y);
        } else if (cmd == "addbefore") {
            int x, y;
            cin >> x >> y;
            addbefore(l, x, y);
        } else if (cmd == "remove") {
            int x;
            cin >> x;
            remove(l, x);
        } else if (cmd == "reverse") {
            reverse(l);
        } else if (cmd == "#") {
            break;
        }
    }
    for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}