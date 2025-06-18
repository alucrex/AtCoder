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

int main(){//オーバーフローしてただけだったんかい
    int n;
    cin >> n;
    v(ll) vec(n,0);
    v(ll) s(n+1,0);
    ll ans = 0;
    rep(i,n){
        cin >> vec[i];
        s[i+1] = s[i] + vec[i];
    }
    rrep(i,n){
        // cout << vec[i] << "*" << vec[i] <<  "- " << 2 << "*" << vec[i] <<"*"<< s[i]<<endl;
        ans += (n-1) * vec[i] * vec[i] - 2 * vec[i] * s[i];
    }
    cout << ans << endl;
}