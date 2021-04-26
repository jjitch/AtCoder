#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

vector<int> a;
int k;

bool capable(int target){
    int former = 0;
    size_t cnt = 0;
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i]-former>=target) {
            cnt++;
            former = a[i];
        }
    }
    return cnt > k ? true : false;
}

int binary_search(int left, int right)
{
    int mid = (left + right) / 2;
    if (mid == left)
    {
        return mid;
    }
    if (capable(mid))
        return binary_search(mid, right);
    else
        return binary_search(left, mid);
}

int main()
{
    int n, l;
    cin >> n >> l >> k;
    a.resize(n, 0);
    for (size_t i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    a.push_back(l);
    int ans = binary_search(0, l);
    cout << ans << endl;
}
