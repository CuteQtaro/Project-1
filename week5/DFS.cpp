#include <bits/stdc++.h>
using namespace std;

void DFSRec(vector<vector<int>> &adj, vector<bool> &visited,int s){
    visited[s] = true;
    cout << s << " ";
    for (int i : adj[s])
        if (visited[i] == false)
            DFSRec(adj, visited, i);
}

void DFS(vector<vector<int>> &adj){
    vector<bool> visited(adj.size(), false);

    for (int i = 1; i < adj.size(); i++){
        if (visited[i] == false){
            DFSRec(adj, visited, i);
        }
    }
}

void addEdge(vector<vector<int>>& adj, int u, int v) { 
    adj[u].push_back(v);
    adj[v].push_back(u); 
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(adj.size(), false);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    DFS(adj);
    return 0;
}
