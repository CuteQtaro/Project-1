//C++ 
#include <bits/stdc++.h> 
using namespace std;

void push(int x, stack<int> &s) 
{ 
    s.push(x); 
}

void pop(stack<int> &s) 
{ 
    cout << s.top() << endl; 
    s.pop(); 
}

int main() 
{ 
    string s;
    stack<int> st;
    while (true) 
    {   cin>>s;
        if (s == "PUSH") 
        { 
            int x; 
            cin >> x; 
            push(x, st); 
        } 
        if (s == "POP") 
        {   if (st.empty()) 
            { 
                cout << "NULL" << endl; 
                continue; 
            }
            pop(st); 
        } 
        if (s == "#") 
        { 
            break; 
        }
    }
    return 0;
}