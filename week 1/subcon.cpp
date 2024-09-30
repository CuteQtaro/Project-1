//C++ 
#include <bits/stdc++.h> 
using namespace std;

const int MOD = 1000000007;

static long arr[1000][1000];

long C(int k, int n){
    if (k==0||k==n) return 1;
    if (k==1&&n==1) return 1;
    if (arr[k][n] != -1)
        return arr[k][n];
    arr[k][n]=(C(k-1, n-1) + C(k, n-1)) % MOD;
    return arr[k][n];
}

int main() 
{   
    int n,k;
    cin>>k>>n;
    memset(arr, -1, sizeof(arr));
    cout<<C(k,n)<<endl;
    return 0;
}