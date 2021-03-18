#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<ll> cum(n);
    rep(i,n){
        if (i==0){
            cum[i] = a[i];
            continue;
        }
        cum[i] = cum[i - 1] + a[i];
    }
    
}
