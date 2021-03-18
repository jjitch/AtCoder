#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin>>n;
    vector<pair<int,int>> a(n), b(n);
    rep(i,n){
        cin >> a[i].first >> b[i].first;
        a[i].second = i;
        b[i].second = i;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a[0].second!=b[0].second){
        cout << max(a[0].first, b[0].first) << endl;
    }else{
        int a_top = a[0].first;
        int b_top = b[0].first;
        int a_nex = a[1].first;
        int b_nex = b[1].first;
        cout << min(a_top + b_top, min(max(a_top, b_nex), max(b_top, a_nex))) << endl;
    }
}
