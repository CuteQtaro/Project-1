#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        if (s.count(x)){ //returns 1 if x is in the set, 0 otherwise, because set only stores unique elements
            cout << 1 << endl;
            continue;
        }
        cout << 0 << endl;
        s.insert(x);
    }
    return 0;
}