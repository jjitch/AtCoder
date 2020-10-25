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
};

int main()
{
    UnionFind *uf = new UnionFind(10);
    cout << uf->find(3) << endl;
    delete uf;
}