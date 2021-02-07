#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[n];
    }
    int s = 1000000005;
    vector<int> seq(s);
    rep(i, n)
    {
        seq[a[i]]++;
    }
    int ans = 0;
    rep(i, s)
    {
        if (seq[i] == 0)
        {
            continue;
        }
        if (seq[i] > i)
        {
            ans += (seq[i] - i);
        }
        if (seq[i] < i)
        {
            ans += i;
        }
    }
    cout << ans << endl;
}
