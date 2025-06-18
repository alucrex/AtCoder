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
#define debug(x) cout << #x" : " << x << endl;
#define Yn(x) cout << ((x) ? "Yes" : "No") << endl;
#define yn(x) cout << ((x) ? "yes" : "no") << endl;
#define mmax(a,b) a = max(a,b)
#define mmin(a,b) a = min(a,b)

int main(){
    int n;
    cin >> n;
    PL mae,ato;
    rep(i,(1<<n-1)){
        PL x = make_pair(-INF,i+1);
        cin >> x.first;
        mmax(mae,x);
    }
    rep(i,(1<<n-1)){
        PL x = make_pair(-INF,(1<<n-1)+i+1);
        cin >> x.first;
        mmax(ato,x);
    }
    cout << (mae.first<ato.first ? mae.second : ato.second) << endl;
}