#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n), up(n);
    rep(i,n){
        cin >> h[i];
    }
    vector<unordered_set<int>> srnd(n, unordered_set<int>());
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        srnd[a].insert(b);
        srnd[b].insert(a);
        up[a]++;
        up[b]++;
    }
    int highest;
    int cnt=0;
    rep(i,n){
        highest = 0;
        if (!up[i]){
            cnt++;
            continue;
        }
        for (int v:srnd[i]){
            highest = max(highest, h[v]);
        }
        if (highest<h[i]){
            cnt++;
        }
    }
    cout << cnt << endl;
}
