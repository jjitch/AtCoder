#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < n; i++)

int main() {
    int k;
    cin >> k;
    int a = 7;
    int ans = 1;
    if (k%2==0||k%5==0){
        cout << (-1) << endl;
        exit(0);
    }
    while (true)
    {
        if (a%k==0){
            break;
        }
        a*=10;
        a += 7;
        a %= k;
        ans++;
    }
    cout << ans << endl;
}
