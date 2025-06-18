#include <bits/stdc++.h>
using namespace std;//とき直せ
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rep1(i,n) for(int i = 1 ; i <= n ; i++)
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define rrep1(i,n) for(int i = n ; i > 0 ; i--)
#define INF 1001001001
#define MOD 1000000007
using ll = int64_t;
using P = pair<int, int>;
using PL = pair<ll,ll>;
using PD = pair<double,double>;
#define v(n) vector<n>
#define vv(n) vector<vector<n>>

int main(){
    int n;
    cin >> n;
    double ans = 0;
    rep1(i,n-1){
        ans += (double)n / (n-i);
    }
    printf("%.10f\n",ans);
}