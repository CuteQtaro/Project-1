#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, int s, vector<bool>& visited){
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty()){
        int curr = q.front();
        cout << curr << " ";
        q.pop();
        for (auto u: adj[curr]){
            if (!visited[u]){
                visited[u] = true;
                q.push(u);
            }
        }
    }
}
void addEdge(vector<vector<int>>& adj, int u, int v){ 
    adj[u].push_back(v);
    adj[v].push_back(u); 
}

void bfsDisLO(vector<vector<int>> &adj, int s, vector<bool>& visited){
    for (int i = 1; i <adj.size(); i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    for (int i = 1; i < adj.size(); i++) {
        if (!visited[i]) {
            bfs(adj, i, visited);
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<bool> visited(adj.size(), false);
    for (int i=0;i<m;i++){
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    bfsDisLO(adj,1,visited);
    return 0;
}