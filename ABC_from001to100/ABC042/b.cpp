#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    int N, L;
    cin >> N >> L;
    vector<string> S;
    rep(i,N) {
        string s;
        cin >> s;
        S.push_back(s);
    }
    sort(S.begin(), S.end());
    string ans;
    rep(i, N) ans += S[i];
    cout << ans << endl;
}