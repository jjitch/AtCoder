#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; i++)
using vll = vector<ll>;
using vvll = vector<vll>;

vvll multiple33(vvll a, vvll b)
{
    vvll ret(3, vll(3));
    rep(i, 3) rep(j, 3) rep(k, 3) ret[i][j] += a[i][k] * b[k][j];
    return ret;
}

vll multiple31(vvll a, vll b)
{
    vll ret(3);
    rep(i, 3) rep(j, 3) ret[i] += a[i][j] * b[j];
    return ret;
}

vvll op3(ll p)
{
    return {{-1, 0, 2 * p}, {0, 1, 0}, {0, 0, 1}};
}

vvll op4(ll p)
{
    return {{1, 0, 0}, {0, -1, 2 * p}, {0, 0, 1}};
}

int main()
{
    vvll op1 = {
        {0, 1, 0},
        {-1, 0, 0},
        {0, 0, 1}};
    vvll op2 = {
        {0, -1, 0},
        {1, 0, 0},
        {0, 0, 1}};
    int n, m, q;
    cin >> n;
    vvll x(n, {0,0,1});
    rep(i, n) cin >> x[i][0] >> x[i][1];
    cin >> m;
    vector<vvll> ops(m + 1);
    ops[0] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    rep(i, m)
    {
        int op;
        ll p = 0;
        cin >> op;
        if (op == 3 || op == 4)
            cin >> p;
        switch (op)
        {
        case 1:
            ops[i + 1] = multiple33(op1, ops[i]);
            break;

        case 2:
            ops[i + 1] = multiple33(op2, ops[i]);
            break;

        case 3:
            ops[i + 1] = multiple33(op3(p), ops[i]);
            break;

        case 4:
            ops[i + 1] = multiple33(op4(p), ops[i]);
            break;

        default:
            break;
        }
    }
    cin >> q;
    rep(i, q)
    {
        int a, b;
        cin >> a >> b;
        vll ans = multiple31(ops[a], x[b - 1]);
        cout << ans[0] << " " << ans[1] << endl;
    }
}