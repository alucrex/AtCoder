#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rep1(i,n) for(int i = 1 ; i < n ; i++)
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i++)
#define INF 1001001001
using ll = int64_t;
using P = pair<int, int>;

struct bag{
    int w = 0;
    int v = 0;
};

int main(){
    int n, w;
    cin >> n >> w;
    vector<bag> b(n+1);
    int vmax = 0;
    rep1(i,n+1){
        cin >> b[i].w >> b[i].v;
        vmax += b[i].v;
    }

    vector<vector<int>> dp(n+1, vector<int>(100001, INF));//今度は価値でdp
    //dp[][] =　重さ
    dp[0][0] = 0;
    int maxj = 0;
    int ans = 0;

    rep(i,n+1)rep(j,100001)dp[i][j]=INF;
    dp[0][0]=0;
    rep1(i,n+1)rep(j,100001){
	    if(j-b[i].v>=0)dp[i][j] = min(dp[i-1][j],dp[i-1][j-b[i].v]+b[i].w);
	    else dp[i][j]=dp[i-1][j];//j-v[i]<0のときはi番目の品物は使えないのだ！
        cout << i << " , " << j << " : " << dp[i][j] << endl;
        if(j > 20)break;
    }
    ans=100000;
    while(dp[n][ans]>w)ans--;
    cout << ans << endl;
}