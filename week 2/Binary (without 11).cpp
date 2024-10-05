#include <bits/stdc++.h>

using namespace std;

vector <int> a;
int n;

void genSequences(int k){
    if (k == n) {
        for (int i = 0; i < n; i++) {
            cout << a[i]; 
        }
        cout << endl;
    }
    else {
        if (a[k - 1] == 1) {
            a[k] = 0;
            genSequences(k + 1);
        }
        else {
            for (int i = 0; i <= 1; i++) {
                a[k] = i;
                genSequences(k + 1);
            }
        }
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        a.push_back(0);
    }
    genSequences(0);
    return 0;
}