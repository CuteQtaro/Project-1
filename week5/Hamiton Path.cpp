#include <bits/stdc++.h>
using namespace std;

bool HamitonPath(vector<vector<int>> &adj, int n){
    int dp[n][1<<n]; // dp[i][mask] is true if there is a Hamiton cycle that ends at i and visits all the vertices in mask
    memset(dp, 0, sizeof(dp)); // initially, no Hamiton cycle exists
    for (int i=0;i<n;i++){
        dp[i][1<<i] = 1; // there is a Hamiton cycle that ends at i and visits only i
    }
    for (int mask=0;mask<(1<<n);mask++){ // mask is the set of vertices visited so far
        for (int i=0;i<n;i++){ // i is the vertex that the Hamiton cycle ends at
            if (mask & (1<<i)){ // if i is in the set of vertices visited so far
                for (int j=0;j<n;j++){ // j is the vertex that the Hamiton cycle visits before i
                    if (mask & (1<<j) && adj[j][i] && i!=j && dp[j][mask^(1<<i)]){ // if j is in the set of vertices visited so far, there is an edge from j to i, i is not equal to j, and there is a Hamiton cycle that ends at j and visits all the vertices in mask except i
                        dp[i][mask] = 1; // there is a Hamiton cycle that ends at i and visits all the vertices in mask
                        break;
                    }
                }
            }
        }
    }
    for (int i=0;i<n;i++){
        if (dp[i][(1<<n)-1]){ // there is a Hamiton cycle that ends at i and visits all the vertices
            return true;
        }
    }
    return false;
}

int main(){
    int t, n, m;
    cin >> t;
    for (int i=0;i<t;i++){
        cin >> n >> m; // n is the number of vertices, m is the number of edges
        vector<vector<int>> adj(n, vector<int>(n, 0)); // adj[i][j] is 1 if there is an edge from i to j
        for (int j=0;j<m;j++){ // input the edges
            int u, v;
            cin >> u >> v;
            adj[u-1][v-1] = 1; 
            adj[v-1][u-1] = 1;
        }
        if (HamitonPath(adj,n)){ // check if there is a Hamiton path
            cout << "1" << endl;
        }
        else{
            cout << "0" << endl;
        }
    }
    return 0;
}