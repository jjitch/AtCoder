#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const long long INF = 1LL << 60;

void showv(vector<ll> x)
{
    for (ll v : x)
    {
        if (v==INF){
            cout << right << setw(7) << setfill(' ') << "INF";
            continue;
        }
        cout << right << setw(7) << setfill(' ') << v;
    }
    cout << endl;
}

void showvv(vector<vector<ll>> a)
{
    for (vector<ll> x : a)
    {
        showv(x);
    }
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

const int MAX_N = 110;
const int MAX_V = 100100;
// const int MAX_N = 7;
// const int MAX_V = 15;

// 入力
int N;
long long W, weight[MAX_N], value[MAX_N]; // 品物の個数は 100 個なので少し余裕持たせてサイズ 110 に




int main()
{
    cin >> N >> W;
    for (int i = 0; i < N; ++i)
        cin >> weight[i] >> value[i];

    // 初期化
    vector<vector<ll>> dp(MAX_N, vector<ll>(MAX_V, INF));

    // 初期条件
    dp[0][0] = 0;

    // DPループ
    for (int i = 0; i < N; ++i)
    {
        for (int sum_v = 0; sum_v < MAX_V; ++sum_v)
        {

            // i 番目の品物を選ぶ場合
            if (sum_v - value[i] >= 0)
                chmin(dp[i + 1][sum_v], dp[i][sum_v - value[i]] + weight[i]);

            // i 番目の品物を選ばない場合
            chmin(dp[i + 1][sum_v], dp[i][sum_v]);
            // showvv(dp);
            // cout << "-----------" << endl;
        }
    }

    // 最適値の出力
    long long res = 0;
    for (int sum_v = 0; sum_v < MAX_V; ++sum_v)
    {
        if (dp[N][sum_v] <= W)
            res = sum_v;
    }
    cout << res << endl;
}