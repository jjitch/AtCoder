#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ll n, w;
    cin >> n >> w;
    vector<ll> weight(n), value(n);
    vector<vector<ll>> dp(n + 1, vector<ll>(1003, 0));
    
}
