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
using PL = pair<ll,ll>;
using PD = pair<double,double>;
#define v(n) vector<n>
#define vv(n) vector<vector<n>>

int main(){
    int n;
    cin >> n;
    v(int) a(n);
    rep(i,n)cin >> a[i];
    ll ans = (ll)1<<31;

    rep(i,1<<(n-1)){
        int o = 0;
        int xorr = 0;
        rep(j,n){
            o |= a[j];
            if(i>>j&1){
                xorr ^= o;
                o = 0;
            }
            if(i == 0 && j == n-1)xorr ^= o;
            else if(j == n - 1)xorr ^= o;
        }
        ans = min(ans,(ll)xorr);
    }
    cout << ans << endl;
}