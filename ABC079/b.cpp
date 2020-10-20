#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[100];

ll lucas(int n){
    if (n==0)
    {
        return 2;
    }
    if (n==1)
    {
        return 1;
    }
    if (dp[n]!=0)
    {
        return dp[n];
    }
    return dp[n] = lucas(n-1) + lucas(n-2);
}


int main() {
    int n;
    cin >> n;
    cout << lucas(n) << endl;
}