#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < n; i++)

int main() {
    unordered_map<string, int> ump;
    int n;
    cin >> n;
    int biggest = 0;
    string ans;
    rep(i,n) {
        string s;
        cin >> s;
        ump[s]++;
        if (ump[s]>biggest) {
            biggest = ump[s];
            ans = s;
        }
    }
    cout << ans << endl;
}