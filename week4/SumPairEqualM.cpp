#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, M;
    cin >> n >> M;
    int countSum = 0;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n); 
    int i = 0, j = n - 1; 
    while (i < j){
        if (a[i] + a[j] == M){ 
            countSum++;
            i++;
            j--;
        }
        else if (a[i] + a[j] < M){ 
            i++;
        }
        else{
            j--;
        }
    }
    cout << countSum << endl;
    return 0;
}