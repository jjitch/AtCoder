#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int odd = 0;
    int even = 0;
    int res = 0;
    string a;
    cin >> a;
    int len = a.length();
    if (len % 2 == 0)
    {
        res = 1;
    }
    for (int i = len - 1; i >= 0; i--)
    {
        if (i % 2 == res)
        {
            odd += a[i] - '0';
        }
        else
        {
            even += a[i] - '0';
        }
    }
    cout << even << " " << odd << endl;
}