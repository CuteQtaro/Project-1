#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

vector<vector<long long>> memo;

// Function to calculate C(k, n) using memoization
long long C(int k, int n) {
    // Base cases
    if (k == 0 || k == n) return 1;
    if (memo[k][n] != -1) return memo[k][n];
    
    // Recursive relation: C(k, n) = C(k-1, n-1) + C(k, n-1)
    memo[k][n] = (C(k-1, n-1) + C(k, n-1)) % MOD;
    return memo[k][n];
}

int main() {
    int k, n;
    cin >> k >> n;
    
    // Initialize the memoization table with -1 (to indicate uncomputed values)
    memo.assign(k + 1, vector<long long>(n + 1, -1));
    
    // Output the result C(k, n) modulo 10^9 + 7
    cout << C(k, n) << endl;
    
    return 0;
}
