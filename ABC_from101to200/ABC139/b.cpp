#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    int now = 1;
    while (now<b) {
        now--;
        now += a;
        cnt++;
    }
    cout << cnt << endl;
}
