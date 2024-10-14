#include <bits/stdc++.h>
using namespace std;

void push(int x, queue<int> &q)
{
    q.push(x);
}

void pop(queue<int> &q)
{
    cout << q.front() << endl;
    q.pop();
}

int main()
{
    string s;
    queue<int> q;
    while (true)
    {
        cin >> s;
        if (s == "PUSH")
        {
            int x;
            cin >> x;
            push(x, q);
        }
        if (s == "POP")
        {
            if (q.empty())
            {
                cout << "NULL" << endl;
                continue;
            }
            pop(q);
        }
        if (s == "#")
        {
            break;
        }
    }
    return 0;
}