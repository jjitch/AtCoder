#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll seek_sum(int t,vector<ll> a) {
    
}

int main() {
    int n;
    ll ans=0;
    cin >> n;
    vector<ll> a(10009);
    for (int i=0; i < n;i++)
    {
        cin >> a[i];
    }
    for (int i=0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    for (int i; i <= n;i++) {
        ll sus = seek_sum(i, a);
        ans = sus > ans ? sus : ans;
    }
}