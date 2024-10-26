#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string s;
    long long hash = 0;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < s.size(); j++){
            hash=(hash*256+s[j])%m;
        }
        cout << hash << endl;
        hash = 0;
    }
    return 0;
}