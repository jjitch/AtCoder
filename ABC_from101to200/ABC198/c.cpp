#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); i++)

int main() {
    int r, x, y;
    cin >> r >> x >> y;
    int a = ( x * x + y * y + r * r - 1 ) / (r * r);
    cout << (int)sqrt(a) << endl;
}
