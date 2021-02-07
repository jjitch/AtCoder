#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    double row_x, row_y, row_r;
    cin >> row_x >> row_y >> row_r;
    ll x = row_x * 10000;
    ll y = row_y * 10000;
    ll r = row_r * 10000;
    cout << x << " " << y << " " << r << endl;
    ll left = x - r;
    ll right = x + r;
    ll top = y + r;
    ll bottom = y - r;
    ll ans = 0;
    for (ll h = bottom; h <= top; h += 10000)
    {
        
    }
}
