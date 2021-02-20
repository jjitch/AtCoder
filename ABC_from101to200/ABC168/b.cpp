#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    if (s.length()>k){
        rep(i,k-s.length()){
            s.pop_back();
        }
        rep(i,3){
            s.push_back('.');
        }
    }
    cout << s << endl;
}
