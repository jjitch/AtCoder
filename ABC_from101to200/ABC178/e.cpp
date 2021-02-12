#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> p(n, pair<ll, ll>(0, 0));
    rep(i, n)
    {
        int x, y;
        cin >> x >> y;
        p[i].first = x - y;
        p[i].second = x + y;
    }
    ll z_min, z_max, w_min, w_max;
    z_min = 10000000000;
    w_min = 10000000000;
    w_max = -10000000000;
    z_max = -10000000000;
    rep(i, n)
    {
        z_min = min(z_min, p[i].first);
        z_max = max(z_max, p[i].first);
        w_min = min(w_min, p[i].second);
        w_max = max(w_max, p[i].second);
    }
    int z_dist, w_dist;
    z_dist = z_max - z_min;
    w_dist = w_max - w_min;
    cout << max(z_dist, w_dist) << endl;
}
