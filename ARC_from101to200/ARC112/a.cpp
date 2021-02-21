#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
    int t;
    cin >> t;
    ll l, r;
    vector<ll> ans(t);
    rep(i,t){
        cin >> l >> r;
        ans[i]=max(max((r - 2 * l + 1),0ll) * max((r - 2 * l + 2),0ll) / 2, 0ll);
    }
    rep(i,t){
        cout << ans[i] << endl;
    }
}
