#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)

template <typename T>
struct RMQ
{
    const T INF = numeric_limits<T>::max();
    int n;
    vector<T> dat;
    RMQ(int n_) : n(), dat(n_ << 2, INF)
    {
        int x = 1;
        while (n_ > x)
            x *= 2;
        n = x;
    }

    void update(int i, T x)
    {
        i += n - 1;
        dat[i] = x;
        while (i > 0)
        {
            i = (i - 1) / 2;
            dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }

    T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
    T query_sub(int a, int b, int k, int l, int r)
    {
        if (r <= a || b <= l)
        {
            return INF;
        }
        else if (a <= l && r <= b)
        {
            return dat[k];
        }
        else
        {
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);
        }
    }
};


int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> con(m, {0, 0});
    rep(i, m) cin >> con[i][0] >> con[i][1];
    int k;
    cin >> k;
    vector<vector<int>> k_s(k, {0, 0});
    vector<int> choise(k);
    rep(i, k) cin >> k_s[i][0] >> k_s[i][1];
    int re = pow(2, k);
    int ans = 0;
    rep(i, re)
    {
        rep(j, k)
        {
            if ((i >> j) & 1 == 1)
            {
                choise[j] = k_s[j][1];
            }
            else
            {
                choise[j] = k_s[j][0];
            }
        }
        int match = 0;
        vector<vector<int>> count(m, {0, 0});
        rep(j, k)
        {
            rep(l, m)
            {
                if (choise[j] == con[l][0])
                {
                    count[l][0]++;
                }
                if (choise[j] == con[l][1])
                {
                    count[l][1]++;
                }
            }
        }
        rep(j, m)
        {
            if (count[j][0] > 0 && count[j][1] > 0)
            {
                match++;
            }
        }
        ans = max(ans, match);
    }
    cout << ans << endl;
}
