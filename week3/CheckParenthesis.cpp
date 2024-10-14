#include <bits/stdc++.h>
using namespace std;

bool checkParenthesis(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty()) return false;
            st.pop();
        }
        if (c=='[') {
            st.push(c);
        } else if (c == ']') {
            if (st.empty()) return false;
            st.pop();
        }
        if (c=='{') {
            st.push(c);
        } else if (c == '}') {
            if (st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s;
    cin >> s;
    cout << (checkParenthesis(s) ? 1 : 0);
    return 0;
}