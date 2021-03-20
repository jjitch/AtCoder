#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define v(x) vector<x>

int main() {
    int n;
    cin >> n;
    v(int) a(n);
    v(int) visited(n,0);
    rep(i,n){
        cin >> a[i];
        a[i]--;
    }
    int next = 0;
    int cnt = 0;
    while (next!=1){
        if (visited[next]){
            cout << -1 << endl;
            exit(0);
        }
        visited[next]++;
        next = a[next];
        cnt++;
    }
    cout << cnt << endl;
}
