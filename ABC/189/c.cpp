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
using PL = pair<ll,ll>;
using PD = pair<double,double>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define v(n) vector<n>
#define vv(n) vector<vector<n>>
#define vvv(n) vector<vector<vector<n>>>
#define line cout << "================================" << endl;

int main(){
    int n;
    cin >> n;
    vi a(n+1);
    rep1(i,n)cin >> a[i];
    ll ans = 0;
    rep1(l,n){
        int pre_min = INF;
        for(int r = l ; r <= n ; r++){
            int comp = a[r];
            pre_min = min(pre_min, comp);
            ans = max(ans, ll(r - l +1)*pre_min);
        }
    }
    cout << ans << endl;
}