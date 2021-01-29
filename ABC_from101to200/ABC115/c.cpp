#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    ll ans = 100000000000;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    sort(h.begin(), h.end());
    // for (auto v:h) cout << v << endl;
    for (int i = 0; i < n - k + 1; i++)
    {
        ll sus = h[i + k - 1] - h[i];
        // cout << sus << endl;
        ans = ans < sus ? ans : sus;
    }
    cout << ans << endl;
}