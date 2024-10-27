#include<bits/stdc++.h>
using namespace std;

const int Max = 100000;

class Edge {
    public:
        int u, v, w;

        Edge(int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}

        bool operator < (const Edge &op) {
            return w < op.w;
        }
};

int parent[Max];
vector<Edge> edges;

void makeSet(int u){
    parent[u] = u;
}

int findSet(int u){
    if(u == parent[u]) return u;
    return parent[u] = findSet(parent[u]);
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    for(int i = 1 ; i <= n ; ++i) makeSet(i);
    sort(edges.begin(), edges.end());
    long long sum = 0;
    for(int i = 0 ; i < m ; ++i){
        Edge e = edges[i];
        int u = findSet(e.u);
        int v = findSet(e.v);
        if(u != v){
            sum += e.w;
            parent[u] = v;
        }
    }
    cout << sum << endl;
    return 0;
}