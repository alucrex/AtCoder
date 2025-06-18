#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rep1(i,n) for(int i = 1 ; i < n ; i++)
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define rrep1(i,n) for(int i = n ; i > 0 ; i--)
#define INF 1001001001
#define MOD 1000000007
using ll = int64_t;
using P = pair<int, int>;

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<bool>> field(h+1, vector<bool>(w+1, true));
    rep1(i,h+1){
        string s;
        cin >> s;
        rep1(j,w+1)field[i][j] = (s[j-1] == '.' ? false : true);//壁→true
    }
    vector<vector<ll>> dp(h+1, vector<ll>(w+1, 0));//dp[i][j]に行く組み合わせ
    dp[1][1] = 1;
    rep1(i,h+1)rep1(j,w+1){
        if(field[i][j])continue;//その地点が壁だった場合
        if(field[i-1][j] && field[i][j-1])continue;
        else if(field[i-1][j])dp[i][j] = dp[i][j-1] % MOD;
        else if(field[i][j-1])dp[i][j] = dp[i-1][j] % MOD;
        else dp[i][j] += (dp[i-1][j] + dp[i][j-1]) % MOD;
    }
    cout << dp[h][w] % MOD << endl;
}