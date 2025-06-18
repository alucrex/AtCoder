#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < (n) ; i++)
#define rep1(i,n) for(int i = 1 ; i <= (n) ; i++)
#define rrep(i,n) for(int i = (n) - 1 ; i >= 0 ; i--)
#define rrep1(i,n) for(int i = (n) ; i > 0 ; i--)
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
#define Yn(x) cout << ((x) ? "Yes" : "No") << endl;
#define yn(x) cout << ((x) ? "yes" : "no") << endl;
#define mmax(a,b) a = max(a,b)
#define mmin(a,b) a = min(a,b)
#define debug(x) cout << #x" : " << (x) << endl;
#define output(x) cout << (x) << endl;
#define mod(n,x) (n) % (x)
#define all(a,b) (a).begin(),(b).end()

class alucrex{
    public:
        int intinput(){int a;cin >> a;return a;}
        ll llinput(){ll a;cin >> a;return a;}
        double dbinput(){double a;cin >> a;return a;}
        long double ldbinput(){long double a;cin >> a; return a;}
};

int main(){
    alucrex al;
    int n = al.intinput();
    vl dp(2,1);
    rep(i,n){
        string s;
        cin >> s;
        vl p(2); swap(dp,p);
        rep(j,2)rep(x,2){
            int nj = j;
            if(s == "AND")nj &= x;
            else nj |= x;
            dp[nj] += p[j]; 
        }
    }
    output(dp[1]);
}