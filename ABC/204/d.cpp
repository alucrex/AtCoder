#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < (n) ; i++)
#define rep1(i,n) for(int i = 1 ; i <= (n) ; i++)
#define rrep(i,n) for(int i = (n) - 1 ; i >= 0 ; i--)
#define rrep1(i,n) for(int i = (n) ; i > 0 ; i--)
#define MOD 1000000007
using ll = int64_t;
using P = pair<int, int>;
using PL = pair<ll,ll>;
using PD = pair<double,double>;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vP = vector<P>;
using p_q = priority_queue<int, vi, greater<int>>;
const int INF = 1001001001;
const ll LINF = (1ll<<62) + ((1ll<<62)-1);
#define v(n) vector<n>
#define vv(n) vector<vector<n>>
#define vvv(n) vector<vector<vector<n>>>
#define p_q(n) priority_queue<(n), v(n), greater<n>>
#define line cout << "================================" << endl;
#define Yn(x) ((x) ? "Yes" : "No")
#define yn(x) ((x) ? "yes" : "no")
#define mmax(a,b) a = max(a,b)
#define mmin(a,b) a = min(a,b)
#define debug(x) cout << #x" : " << (x) << endl;
#define output(x) cout << (x) << endl;
#define outs(x) cout << #x << endl;
#define mod(n) %(n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
template <typename T> void chmin(T& a, T b){if(a>b)a=b;}
template <typename T> void chmax(T& a, T b){if(a<b)a=b;}

class alucrex{
    public:
    void vin(vi& a){rep(i,a.size())cin>>a[i];}
    void vin1(vi& a){rep1(i,a.size())cin>>a[i];}
    void vvin(vvi& a){rep(i,a.size())rep(j,a[i].size())cin>>a[i][j];}
    void vvdes(vvi& a){rep(i,a.size()){rep(j,a[i].size()){
        cout << a[i][j] << " ";}cout<<endl;
    }}
    void vinl(vl& a){rep(i,a.size())cin>>a[i];}
    void vvinl(vvl& a){rep(i,a.size())rep(j,a[i].size())cin>>a[i][j];}
    void vvdesl(vvl& a){rep(i,a.size()){rep(j,a[i].size()){
        cout << a[i][j] << " ";}cout<<endl;
    }}
    void vpin(vP& a){for(auto& x:a)cin>>x.first>>x.second;}
    template<typename T>
    void vvd(vv(T)& a){rep(i,a.size()){rep(j,a[i].size()){
        cout << a[i][j] << " ";}cout<<endl;
    }}
};

int solve(vi& time) {
    bitset<100001> dp;
    dp[0] = 1;
    int tot = 0;
    for(int t : time) {
        tot += t;
        dp |= dp<<t;
    }
    int ans = tot;
    rep(i,tot+1) if (dp[i]) ans = min(ans, max(i,(tot-i)));
    return ans;
}

int mysolve(vi& time) {
    bitset<100001> dp;
    dp = 1;
    int tot = 0;
    for(int t : time) {
        dp |= dp << t;
        tot += t;
    }
    int ans = INF;
    rep(i, tot+1) if(dp[i]) chmin<int> (ans , max(i , tot - i));
    return ans;
}

int main(){
    alucrex al;
    int n; cin >> n;
    bitset<100001> dp;
    dp = 1;
    int tot = 0;
    rep(i,n) {
        int t; cin >> t;
        dp |= dp << t;
        tot += t;
    }
    int ans = INF;
    rep(i, tot+1) if(dp[i]) chmin<int> (ans , max(i , tot - i));
    cout << ans << endl;
    // int n, m; cin >> n >> m;
    // rep(i, m) {
    //     vi r_num(n); for(int&i : r_num) i = rand() mod(100);
    //     int ans1 = mysolve(r_num), ans2 = solve(r_num);
    //     if(ans1 != ans2) {
    //         debug(i);
    //         debug(ans1);debug(ans2);
    //         for(int r : r_num) cout << r << " ";puts("");
    //         return 0;
    //     }
    // }
}