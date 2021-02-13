#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)


void change(vector<int> a){
    a[0] = 325;
}


int main() {
    vector<int> a = {2, 9, 8};
    cout << a[0] << endl;
    change(a);
    cout << a[0] << endl;
}
