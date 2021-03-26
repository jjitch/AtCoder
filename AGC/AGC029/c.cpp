#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
    string s;
    cin >> s;
    int t = s.size();
    int bcnt = 0;
    ll ans = 0;
    rep(i,t){
        if (s[i]=='B')
        {
            bcnt++;
            ans += t - i - bcnt;
        }
        
    }
    cout << ans << endl;
}
