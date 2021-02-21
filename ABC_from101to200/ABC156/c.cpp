#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    ll n;
    cin >> n;
    ll ans = 1 << 30;
    vector<ll> x(n);
    ll x_max = 0;
    rep(i, n)
    {
        cin >> x[i];
        x_max = max(x_max, x[i]);
    }
    ll cost;
    rep(p, x_max+1)
    {
        cost = 0;
        {
            for (ll v : x)
            {
                cost += (v - p) * (v - p);
            }
        }
        ans = min(cost, ans);
    }
    cout << ans << endl;
}
