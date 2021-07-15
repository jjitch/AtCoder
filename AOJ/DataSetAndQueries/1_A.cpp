#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i, n) for (i64 i = 0; i < (n); i++)
#define IN_i64(n) \
    i64 n; \
    cin >> n;
#define IN_veci64(a, n) \
    vector<i64> a((n)); \
    rep(i, n) cin >> a[i];
constexpr i64 INF64 = 1LL << 62LL;
inline i64 modpow(i64, i64, i64 = INF64);
inline i64 gcd(i64, i64);
template <class T> inline bool chmax(T &a, T b);
template <class T> inline bool chmin(T &a, T b);

struct WeightedEdge
{
    i64 from;
    i64 to;
    i64 cost;
    WeightedEdge(i64 _from, i64 _to, i64 _cost) : from(_from), to(_to), cost(_cost) {}
    bool operator>(const WeightedEdge &other) const { return cost > other.cost; }
    bool operator<(const WeightedEdge &other) const { return cost < other.cost; }
};

struct UnionFind
{
    vector<int> root, rank;
    UnionFind(size_t num)
    {
        root.resize(num, -1);
        rank.resize(num, 1);
    }
    bool isRoot(size_t i) { return root[i] == -1; }
    size_t find(size_t i)
    {
        if (isRoot(i)) return i;
        size_t r(find(root[i]));
        root[i] = r;
        return r;
    }
    bool isSame(size_t a, size_t b) { return find(a) == find(b); }
    void unite(size_t a, size_t b)
    {
        if (isSame(a, b)) return;
        const size_t root_a(find(a));
        const size_t root_b(find(b));
        const size_t high = rank[root_a] > rank[root_b] ? root_a : root_b;
        const size_t lower = rank[root_a] > rank[root_b] ? root_b : root_a;
        chmax(rank[high], rank[lower] + 1);
        root[lower] = high;
    }
    void show()
    {
        cout << "--------------" << endl;
        cout << "indx:";
        rep(i, root.size()) cout << setw(3) << i << " ";
        cout << endl;
        cout << "root:";
        rep(i, root.size()) cout << setw(3) << root[i] << " ";
        cout << endl;
        cout << "rank:";
        rep(i, rank.size()) cout << setw(3) << rank[i] << " ";
        cout << endl;
    }
};

int main()
{
    IN_i64(n);
    IN_i64(q);
    UnionFind uf(n);
    rep(i, q)
    {
        IN_i64(c);
        IN_i64(x);
        IN_i64(y);
        if (c) { cout << uf.isSame(x, y) << endl; }
        else
        {
            uf.unite(x, y);
        }
    }
}

i64 modpow(i64 base, i64 ex, i64 mod)
{
    i64 ans = 1;
    while (ex > 0)
    {
        if (ex % 2 == 1)
        {
            ans *= base;
            ans %= mod;
        }
        ex /= 2;
        base *= base;
        base %= mod;
    }
    return ans;
}

i64 gcd(i64 a, i64 b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

template <class T> inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T> inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
