#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    map<int, int> b;
    for(int i = 0; i < n; i++){
        cin >> a[i]; 
        b[a[i]]++; 
        if (b[a[i]] >= 2) cout << 1 << endl; 
        else cout << 0 << endl;
    }
    return 0;
}