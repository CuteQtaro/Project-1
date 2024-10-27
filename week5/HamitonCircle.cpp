#include <bits/stdc++.h>
using namespace std;
#define M 1000

int n, m;

int A[M][M];
int szA[M];
bool visited[M];

void input() {
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= n; ++i) {
        szA[i] = 0;
        visited[i] = false;
    }
    for(int i = 1; i <= m; ++i) {
        cin >> u >> v;
        A[u][szA[u]] = v;
        A[v][szA[v]] = u;
        szA[u]++;
        szA[v]++;
    }
}

void dfs(int u) {
    visited[u] = true;
    cout << u << " ";
    int k = szA[u];
    for(int i = 0; i < k; ++i) {
        if(visited[A[u][i]] == false) {
                dfs(A[u][i]);
        }
    }
}


int main() {
    input();
    for(int i = 1; i <= n; ++i) {
        if(visited[i] == false) {
            dfs(i);
        }
    }
    return 0;
}