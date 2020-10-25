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
    bool same(ll x, ll y)
    {
        return find(x) == find(y);
    }
    int show_rank(ll x){
        return rank[x];
    }
};

int main()
{
    ll n = 10;
    UnionFind *uf = new UnionFind(n);
    uf->unite(0,1);
    uf->unite(1,2);
    uf->unite(2,3);
    uf->unite(4,5);
    uf->unite(5,6);
    for (auto i = 0; i < n; i++)
    {
        cout << "par " << uf->find(i) << endl;
        cout << "rank " << uf->show_rank(i) << endl;
    }
    cout << "-----" << endl;
    uf->unite(0,4);
    for (auto i = 0; i < n; i++)
    {
        cout << "par " << uf->find(i) << endl;
        cout << "rank " << uf->show_rank(i) << endl;
    }
    delete uf;
}