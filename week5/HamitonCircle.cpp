#include <bits/stdc++.h>
using namespace std;



int main(){
    int t, n, m;
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> n >> m; 
        vector<vector<int>> adj(n, vector<int>(n, 0)); 
        for (int j=0;j<m;j++){
            int u, v;
            cin >> u >> v;
            adj[u-1][v-1] = 1; 
            adj[v-1][u-1] = 1;
        }
        if (HamitonPath(adj,n)){ 
            cout << "1" << endl;
        }
        else{
            cout << "0" << endl;
        }
    }
    return 0;
}