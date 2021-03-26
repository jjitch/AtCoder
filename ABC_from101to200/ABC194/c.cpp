#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
    ll n;
    cin >> n;
    ll cum = 0;
    ll sq_cum = 0;
    rep(i,n){
        ll a;
        cin >> a;
        cum += a;
        sq_cum += a * a;
    }
    ll ans = n * sq_cum - cum * cum;
    cout << ans << endl;
}
