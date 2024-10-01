#include <bits/stdc++.h>
using namespace std;

void generate(vector<int> &a, int n){
    if(n==1){
        for(auto x: a) cout<<x<<" ";
        cout<<endl;
        return;
    }
    for(int i=0; i<n-1; i++){
        generate(a, n-1);
        if(n%2==0) swap(a[i], a[n-1]);
        else swap(a[0], a[n-1]);
    }
    generate(a, n-1);
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) a[i]=i+1;
    generate(a, n);
    return 0;
}