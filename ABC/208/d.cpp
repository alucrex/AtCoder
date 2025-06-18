#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
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
using vvP = vector<vP>;
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
#define set_time(x) steady_clock::time_point (x) = steady_clock::now()
#define show_time(s, e) cout << "実行時間" << duration_cast<milliseconds>(e-s).count() << "ms\n"
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

int n;
vvP to;

void dijkstra(vvi& dp, int pos) {
    queue<int> q,  q_; q.push(pos);
    while(!q.empty()) {
        int qt = q.front(); q.pop();
        for(auto u : to[qt]) {
            q_.push(u.first);
            mmin(dp[qt][u.first] , u.second);
        }
        if(q.empty())swap(q, q_);
    }
}

void dfs(vvi& dp, int s, int p) {
    for(auto u : to[p]){
        mmin(dp[s][u.first] , dp[s][p] + dp[p][u.first]);
        dfs(dp, u.first, s);
    }
}

int dfs2(vvi& dp, int p, int k, int g) {
    int res = INF;
    int U = 0;
    if(p == g) {
        debug(p);debug(g);
        return dp[p][g];
    }
    for(auto u : to[p]) {
        if(u.first > k)continue;
        int a = dfs2(dp, u.first, k, g);
        if(res > a) {
            res = a;
            U = u.first;
        }
    }
    return res + dp[p][U];
}

int main(){
    set_time(__start__);
    alucrex al;
    int m; cin >> n >> m;
    n++;
    to.resize(n);
    vvi dp(n, vi(n, INF));
    rep(i, m) {
        int f, t, c; cin >> f >> t >> c;
        to[f].push_back(make_pair(t, c));
    }
    puts("hi");
    rep1(s, n-1) {
        dijkstra(dp, s);
    }
    line;
    rep(i, n)rep(j, n) {
        if(i == j) dp[i][j] = 0;
        dfs(dp, i, j);
    }
    al.vvdes(dp);
    // line
    // ll ans = 0;
    // rep1(s, n-1)rep1(t, n-1)rep(k , n-1) {
    //     if(s == t) continue;
    //     if(dp[s][t] == INF) continue;
    //     int res = dfs2(dp, s, k, t);
    //     // debug(res);
    //     if(res >= INF)continue;
    //     ans += res;
    // }
    // cout << ans << endl;

    set_time(__end__);
    show_time(__start__ , __end__);
}