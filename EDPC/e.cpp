#include <bits/stdc++.h>//解説見ました…
using namespace std;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rep1(i,n) for(int i = 1 ; i < n ; i++)
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define INF 1001001001
using ll = int64_t;
using P = pair<int, int>;

struct bag{
    ll w = 0;
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

    vector<vector<ll>> dp(n+1, vector<ll>(vmax+1, INF));//今度は価値でdp
    //dp[][] =　重さ
    dp[0][0] = 0;
    int maxj = 0;

    rep1(i,n+1)rep(j, vmax+1){
           
        if(j < b[i].v){
            dp[i][j] = dp[i-1][j];
        }else{
            dp[i][j] = min(dp[i-1][j], dp[i-1][j-b[i].v] + b[i].w);
        }

        // maxj = max(maxj, j);
        // if(dp[i][j] >= w)break;
    }
    // rep(i,n+1)rep(j,vmax+1){
    //     cout << "( " << i << " , " << j << " ) " << dp[i][j] << endl;;
    // }
    rrep(j, vmax+1){
        if(dp[n][j] <= w){
            cout << j << endl;
            break;
        }
    }
}