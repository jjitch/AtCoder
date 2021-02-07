#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> field(H), copied_field(H);
    rep(i, H) cin >> field[i];
    int ans = 0;
    int all_state = pow(2,(H+W));
    rep(state, all_state)
    {
        int cnt = 0;
        copied_field = field;
        rep(i, W)
        {
            if ((state >> i) & 1 == 1)
            {
                rep(h, H)
                {
                    copied_field[h][i] = '.';
                }
            }
        }
        rep(i, H)
        {
            if ((state >> (W + i)) & 1 == 1)
            {
                rep(w, W)
                {
                    copied_field[i][w] = '.';
                }
            }
        }
        rep(i, H) rep(j, W) if (copied_field[i][j] == '#') cnt++;
        if (cnt == K)
            ans++;
    }
    cout << ans << endl;
}
