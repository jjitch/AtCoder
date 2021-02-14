#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define max_tri(a,b,c) max(a, max(b,c))

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> points(3);
    cin >> points[0] >> points[1] >> points[2];
    string t;
    cin >> t;
    vector<vector<int>> dp(n, vector<int>(3, 0));
    int win;
    char c;
    rep(i,n){
        c = t[i];
        win = c == 'r' ? 2 : c == 's' ? 0 : 1;
        if(i<k){
            if(i!=0){
                rep(j,3){
                    dp[i][j] = max_tri(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);
                }
            }
            dp[i][win] += points[win];
        }else{
            dp[i][0] = max(dp[i - k][1], dp[i - k][2]);
            dp[i][1] = max(dp[i - k][0], dp[i - k][2]);
            dp[i][2] = max(dp[i - k][1], dp[i - k][0]);
            dp[i][win] += points[win];
        }
    }
    cout << max_tri(dp[n-1][0], dp[n-1][1], dp[n-1][2]) << endl;
    cout << 111 << endl;
}
