#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = 0;
    for (int l = 0; l < n;l++)
    {
        int m = INT32_MAX;
        for (int r = l; r < n;r++)
        {
            m=min(m,a[r]);
            ans = max(ans, m * (r - l + 1));
        }
    }
    cout << ans << endl;
}
