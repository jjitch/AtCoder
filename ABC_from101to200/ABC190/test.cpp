#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < n; i++)

int main() {
    int n = 4;
    int x = pow(2, n);
    rep(i,x){
        // cout << bitset<8>(i) << endl;
        rep(j,n){
            if ((i>>j)&1==1) {
                cout << "found" << ' ';
            } else {
                cout << "not" << ' ';
            }
        }
        cout << endl;
    }
}
