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
    int n;
    cin >> n;
    vector<double> p(n+1,0);
    rep1(i,n+1)cin >> p[i];
    vector<vector<double>> dp(n+1, vector<double>(n+1,0));
    dp[0][0] = 1;

    rep1(i,n+1)for(int j = 0 ; j <= i ; j++){
        if(j == 0)dp[i][j] = dp[i-1][j] * (1 - p[i]);
        else dp[i][j] += dp[i-1][j-1] * p[i] + dp[i-1][j] * (1 - p[i]);
    }
    
    // rep(i,n+1){for(auto x : dp[i])cout << x << "\t" ;cout << endl;}
    double ans = 0;
    for(int i = n/2 + 1 ; i <= n ; i++){
        ans += dp[n][i];
    }
    printf("%.10f\n",ans);
}