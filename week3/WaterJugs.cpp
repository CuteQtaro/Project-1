#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { 
    if (b == 0) return a;
    return gcd(b, a % b);
}

int pour(int fromJug, int toJug, int c){
    int from = fromJug;
    int to = 0;

    int step = 1;

    while (from != c && to != c){
        int temp = min(from, toJug - to);

        to += temp;
        from -= temp;

        step++;

        if (from == c || to == c) break;

        if (from == 0){
            from = fromJug;
            step++;
        }

        if (to == toJug){
            to = 0;
            step++;
        }
    }
    return step;
}

int minSteps(int a, int b, int c){
    if (a > b) swap(a, b);
    
    if (c > b) return -1;
    if (c % gcd(b, a) != 0) return -1;
    if (c == a || c == b) return 1;
    if (c == 0) return 0;

    return min(pour(a, b, c), pour(b, a, c));
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << minSteps(a, b, c) << endl;
    return 0;
}