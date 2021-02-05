#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n - 1);
    vector<vector<int>> t(n, vector<int>(n, 0));
    rep(i, n) rep(j, n) cin >> t[i][j];
    int now = 0;
    int ans = 0;
    int cost = 0;
    for (int i = 1; i < n; i++)
    {
        a[i - 1] = i;
    }
    do
    {
        a.push_back(0);
        now = 0;
        cost = 0;
        rep(i,n){
            cost += t[now][a[i]];
            now = a[i];
        }
        if (cost==k)
            ans++;
        a.pop_back();
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << endl;
}
