#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rep1(i,n) for(int i = 1 ; i <= n ; i++)
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define rrep1(i,n) for(int i = n ; i > 0 ; i--)
#define INF 1001001001
#define MOD 1000000007
using ll = int64_t;
using P = pair<int, int>;

double f(int, int, int);
int n;
int c1, c2, c3;
vector<vector<vector<double>>> dp(310, vector<vector<double>>(310, vector<double>(310, 0)));
int main(){
    cin >> n;
    vector<int> sushi(n,0);
    int c1 = 0, c2 = 0, c3 = 0;
    rep1(i,n){
        cin >> sushi[i];
        switch(sushi[i]){
            case 1 : c1++;break;
            case 2 : c2++;break;
            case 3 : c3++;break;
        }
    }
    cout << "c1 : " << c1 << " / c2 : " << c2 << " / c3 : " << c3 << endl;
    cout << f(c1, c2, c3) << endl;
}

double f(int i, int j, int k){
    if(dp[i][j][k]>0)return dp[i][j][k];
    if(i == 0 && j == 0 && k == 0)return 0;
    // rep(i,c1+1)rep(j,c2+1)rep(k,c3+1){
    //     cout << i << " , " << j << " , " << k << endl;
    //     dp[i][j][k] += dp[i][j][k-1] + ((double)1 / i+j+k )* 3;
    // }
    if(i>0)dp[i][j][k] += f(i-1, j, k) * i;
    if(j>0)dp[i][j][k] += f(i+1, j-1, k) * j;
    if(k>0)dp[i][j][k] += f(i, j+1, k-1) * k;
    dp[i][j][k] += n;
    dp[i][j][k] *= (double)1 / i + j + k;
    return dp[i][j][k];
}