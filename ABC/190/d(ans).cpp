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

ll f(ll num){
    while(num % 2 == 0)num/=2;
    return num;
}

v(PL) soin(ll num){
    v(PL) ans;
    for(ll i = 1 ; i*i <= num ; i++){
        if(num % i == 0){
            ans.push_back(make_pair(i,num/i));
        }
    }
    return ans;
}

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    auto pr = soin(f(n));
    auto itr = pr.end();
    itr--;
    auto x = *itr;
    if(x.first == x.second)ans = (pr.size()*2-1)*2;
    else ans = pr.size()*2*2;
    cout << ans << endl;
}