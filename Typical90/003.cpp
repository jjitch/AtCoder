#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i, n) for (i64 i = 0; i < (n); i++)
constexpr i64 INFLL = 1LL << 62LL;
inline i64 powll(i64, i64, i64 = INFLL);
inline i64 gcd(i64, i64);

vector<set<i64>> vertex;
vector<set<i64>> vertex2;
vector<i64> dist;

void dfs1(i64 from, i64 depth)
{
    dist[from] = depth;
    depth++;
    for (i64 next : vertex[from])
    {
        vertex[next].erase(from);
        dfs1(next, depth);
    }
    return;
}

void dfs2(i64 from, i64 depth)
{
    dist[from] = depth;
    depth++;
    for (i64 next : vertex2[from])
    {
        vertex2[next].erase(from);
        dfs2(next, depth);
    }
    return;
}

int main()
{
    i64 n;
    cin >> n;
    vertex.resize(n, set<i64>());
    dist.resize(n);
    rep(i, n - 1)
    {
        i64 a, b;
        cin >> a >> b;
        a--;
        b--;
        vertex[a].insert(b);
        vertex[b].insert(a);
    }
    vertex2=vertex;
    dfs1(0, 0);
    size_t far = distance(dist.begin(), max_element(dist.begin(), dist.end()));
    dfs2(far, 0);
    cout << (*max_element(dist.begin(), dist.end())) + 1 << endl;
}

inline i64 powll(i64 base, i64 exp, i64 mod)
{
    i64 ans = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            ans *= base;
            ans %= mod;
        }
        exp /= 2;
        base *= base;
        base %= mod;
    }
    return ans;
}

inline i64 gcd(i64 a, i64 b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
