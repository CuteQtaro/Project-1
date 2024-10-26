#include <bits/stdc++.h>
using namespace std;

int find(vector<string> &v, string s){
    for (int i = 0; i < v.size(); i++){
        if (v[i] == s) return 1;
    }
    return 0;
}

int insert(vector<string> &v, string s){
    if (find(v, s) == 0){
        v.push_back(s);
        return 1; 
    }
    return 0; 
}

int main(){
    vector<string> v;
    string s;
    while(cin >> s){
        if (s.length() <0 || s.length()>50) break;
        if (s == "*") break;
        v.push_back(s);
    }
    string cmd, param;
    while(cin >> cmd){
        if (cmd == "***") break;
        cin >> param;
        if (cmd == "find"){
            cout << find(v, param) << endl;
        }
        if (cmd == "insert"){
            cout << insert(v, param) << endl;
        }
    }
    return 0;
}