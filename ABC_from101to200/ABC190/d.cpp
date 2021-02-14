#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    ll n;
    cin >> n;
    ll cnt = 0;
    unordered_set<ll> d={};
    n += n;
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n%i==0){
            if (i%2!=(n/i)%2){
                cnt++;
            }
        }
    }
    cout << 2*cnt << endl;
}
