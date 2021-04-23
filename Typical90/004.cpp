#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> vals(h, vector<int>(w, 0));
    rep(i, h) rep(j, w) cin >> vals[i][j];
    vector<int> row(h, 0);
    vector<int> col(w, 0);
    rep(i, h) rep(j, w) row[i] += vals[i][j];
    rep(i, h) rep(j, w) col[j] += vals[i][j];
    int ans = 0;
    rep(i, h)
    {
        rep(j, w)
        {
            ans += row[i];
            ans += col[j];
            ans -= vals[i][j];
            cout << ans;
            if (j < w - 1)
                cout << " ";
            ans = 0;
        }
        cout << endl;
    }
}
