#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    ll n, x, m;
    cin >> n >> x >> m;
    vector<int> a(m);
    ll ans = x;
    int i = 1;
    int start;
    while (true)
    {
        if (a[x])
        {
            start = a[x];
            break;
        }
        if (n == i)
        {
            cout << ans << endl;
            exit(0);
        }
        a[x] = i;
        x *= x;
        x %= m;
        i++;
        ans += x;
    }
    ll left = n - start;
    ll loop_len = i - start;
    ll res = left % loop_len;
    ll loop_need = left / loop_len;

    cout << "i" << i << "x" << x << "s" << start << endl;
    cout << "left " << left << endl;
    cout << "loop_len " << loop_len << endl;
    cout << "res " << res << endl;
    cout << "loop_need " << loop_need << endl;

    ll lp_value = 0, res_value = 0;
    rep(j, loop_len)
    {
        lp_value += x;
        x *= x;
        x %= m;
        if (j == res - 1)
        {
            res_value = lp_value;
        }
    }
    ans += (lp_value * loop_need + res_value);
    cout << ans << endl;
}
