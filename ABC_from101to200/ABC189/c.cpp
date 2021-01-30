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
    int n;
    cin >> n;
    RMQ<int> rmq(n);
    rep(i, n)
    {
        int a;
        cin >> a;
        rmq.update(i, a);
    }
    int ans = 0;
    for (int l = 0; l < n; l++)
    {
        for (int r = l + 1; r < n + 1; r++)
        {
            int m = rmq.query(l, r);
            ans = max(ans, m * (r - l));
        }
    }
    cout << ans << endl;
}
