#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll r = 0;
    while (x < b)
    {
        r++;
        x *= a;
        if (x >= y)
        {
            cout << r - 1 << endl;
            exit(0);
        }
    }
    cout << r + (y - x - 1) / b << endl;
}
