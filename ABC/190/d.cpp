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
using PL = pair<ll, ll>;
using PD = pair<double,double>;
#define v(n)  vector<n>
#define vv(n) vector<vector<n>>

v(PL) soin(int num){
    v(PL) ans;
    for(ll i = 1 ; i*i <= num ; i++){
        if(num % i == 0){
            ans.push_back(make_pair(i,num/i));
        }
    }
    return ans;
}

int solve(int num){
    v(PL) ya = soin(num);
    ll ans =0;
    for(int i = 0 ; i < ya.size() ; i++){
        if(ya[i].first - ya[i].second % 2 && ya[i].first + ya[i].second % 2){
            // int a = ya[i].first, b = ya[i].second;
            ans++;
        }
    }
    return ans;
}

int main(){
    ll n;
    cin >> n;
    // ll ans = solve(n*2);
    // if(n == 1 || n == -1)ans++;
    // cout << ans << endl;
    auto pr = soin(n);
    ll ans = 0;
    ans = pr.size() *4;
    cout << ans << endl;
}
//a....bの和
// ((a+b)*size)
// ------------
//      2