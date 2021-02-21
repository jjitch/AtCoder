#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    int n, w;
    cin >> n >> w;
    int num = 200005;
    vector<ll> p(n);
    vector<pll> st(n, pll());
    rep(i, n)
    {
        cin >> st[i].first >> st[i].second >> p[i];
    }
    vector<ll> cost(num);
    ll cum = 0;
    rep(i,n){
        cost[st[i].first] += p[i];
        cost[st[i].second] -= p[i];
    }
    rep(i,num){
        cum += cost[i];
        if (cum>w){
            cout << "No" << endl;
            exit(0);
        }
    }
    cout << "Yes" << endl;
}
