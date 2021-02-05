#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll dis_max = 0;
    ll dis = 0;
    ll crd = 0;
    ll ans = 0;
    rep(i,n) cin >> a[i];
    rep(i, n)
    {
        dis += a[i];
        dis_max = max(dis_max, dis);
        ans = max(ans, crd + dis_max);
        crd += dis;
    }
    cout << ans << endl;
}
