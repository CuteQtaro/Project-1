#include <iostream>
#include <bitset>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    for (int i = 0; i < (1 << n); i++) {
        bitset<32> a(i); // 32-bit binary representation of i, a is just a variable name
        cout << a.to_string().substr(32-n) << endl;
        // substr(32-n) to remove leading zeros
    }
    return 0;
}