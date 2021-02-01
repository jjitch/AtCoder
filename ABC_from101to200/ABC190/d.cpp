#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    ll n;
    cin >> n;
    ll cnt = 0;
    ll tar = sqrt(n) + 1;
    rep(i,tar){
        ll s = 2 * n % tar;
        if (s==0)
        {
            if ((s-n+1)%2==0){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
