#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] <<" ";
    }
    cout<<endl;
}

void Permutation(int n, int arr[], int i, int used[])
{
    if (i == n) {
        print(arr, n);
        return;
    }
    for (int j = 0; j < n; j++) {
        if (used[j] == 0) {
            arr[i] = j + 1; //add 1 to make it 1-indexed
            used[j] = 1; //mark the number as used
            Permutation(n, arr, i + 1, used); //recursive call to the next index
            used[j] = 0; //unmark the number
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int used[n];
    for (int i = 0; i < n; i++) {
        used[i] = 0;
    }
    Permutation(n, arr, 0, used);
    return 0;
}