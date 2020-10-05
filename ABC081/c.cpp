#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    ll first = 0;
    ll second = 0;
    ll ans = 0;
    bool f = false;
    for (auto i = 1; i < n - 1; i++)
    {
        if (a[i - 1] == a[i] && !f)
        {
            first = a[i];
            f = true;
            continue;
        }

        if (a[i] == a[i + 1] && f)
        {
            second = a[i];
            ans = first * second;
            break;
        }
    }
    cout << ans << endl;
}