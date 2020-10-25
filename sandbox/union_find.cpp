#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class UnionFind
{
private:
    vector<ll> par;
    vector<ll> rank;

public:
    UnionFind(ll n)
    {
        for (auto i = 0; i < n; i++)
        {
            par.push_back(i);
            rank.push_back(0);
        }
    }
    int find(ll x)
    {
        if (par[x] == x)
        {
            return x;
        }
        else
        {
            return par[x] = find(par[x]);
        }
    }
    void unite(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (rank[x] < rank[y])
        {
            par[x] = y;
        }
        else
        {
            par[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }
};

int main()
{
    ll n=10;
    UnionFind *uf = new UnionFind(n);
    cout << uf->find(3) << endl;
    uf->unite(0, 1);
    uf->unite(0,2);
    for (auto i = 0; i < n; i++)
    {
        cout << uf->find(i) << endl;
    }
    
    delete uf;
}