#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
#define rep(i,n) for(int i = 0 ; i < (n) ; i++)
#define rep1(i,n) for(int i = 1 ; i <= (n) ; i++)
#define rrep(i,n) for(int i = (n) - 1 ; i >= 0 ; i--)
#define rrep1(i,n) for(int i = (n) ; i > 0 ; i--)
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
template<typename T> using v = vector<T>;
template<typename T> using vv = vector<vector<T>>;
template<typename T> using vvv = vector<vector<vector<T>>>;
template<typename T> using p_q = priority_queue<T, v<T>, greater<T>>;
const int INF = 1001001001;
const int INTMAX = (1ll<<31)-1;
const ll LINF = (1ll<<62);
const ll LLMAX = (1ll<<62) + ((1ll<<62)-1);
#define line cout << "================================" << endl;
#define Yn(x) ((x) ? "Yes" : "No")
#define yn(x) ((x) ? "yes" : "no")
#define debug(x) cout << #x" : " << (x) << endl;
#define output(x) cout << (x) << endl;
#define outs(x) cout << #x << endl;
#define mod(n) %(n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define m_p(a, b) make_pair(a, b)
#define set_time(x) steady_clock::time_point (x) = steady_clock::now()
#define p_time(x) duration_cast<milliseconds>(x).count()
#define show_time(s, e) cout << "実行時間" << duration_cast<milliseconds>(e-s).count() << "ms\n"
template <typename T> bool chmin(T& a, T b){if(a>b){a=b;return 1;}return 0;}
template <typename T> bool chmax(T& a, T b){if(a<b){a=b;return 1;}return 0;}
ostream& operator<< (ostream& os, P a) {return os << a.first << " , " << a.second;}

class alucrex{
    public:
    void vin(vi& a){for(auto& i:a)cin>>i;}
    void vin(vl& a){for(auto& i:a)cin>>i;}
    void vin(vP& a){for(auto& x:a)cin>>x.first>>x.second;}
    void vin1(vi& a){rep1(i,a.size()-1)cin>>a[i];}
    void vvin(vvi& a){for(auto& i:a)for(auto& j:i)cin>>j;}
    void vvin(vvl& a){for(auto& i:a)for(auto& j:i)cin>>j;}
    void vvdes(vvi& a){for(auto& i:a){for(auto& j:i){
        cout << j << " ";}puts("");
    }}
    void vvdes(vvl& a){for(auto& i:a){for(auto& j:i){
        cout << j << " ";}puts("");
    }}
    template<typename T>
    void vvd(vv<T>& a){rep(i,a.size()){rep(j,a[i].size()){
        cout << a[i][j] << " ";}cout<<endl;
    }}
    bool TLE(steady_clock::time_point s, int time = 9800){
        steady_clock::time_point e = steady_clock::now();
        if(duration_cast<milliseconds>(e - s).count() >= time){puts("TLE");return true;}
        return false;
    }
    ll rui(ll n, int r, ll m = LLMAX) {
        n %= m;
        ll res = (r < 2 ? 1 : n);
        ll cnt = 1;
        if(r >= 2)for( ; cnt *2 <= r ; cnt *= 2) {
            res *= res;
            res %= m;
        }
        else cnt = 0;
        for(int i = 0 ; i < (r - cnt) ; i++) {res *= n; res %= m;}
        return res;
    }
    ll kai(ll n) { //O(N)
        ll res = 1;
        for(int i = 2 ; i <= n ; i++) res *= i;
        return res;
    }
};
const int MOD = 1000000007;

void solve() {
    alucrex al;
    int n, m; cin >> n >> m;
    vi col(n); al.vin(col);
    vvi to(n);
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--, v--;
        to[u].emplace_back(v);
        to[v].emplace_back(u);
    }
    vvi dist(n, vi(n, INF));
    queue<P> q;
    auto push = [&](int i, int j, int d) {
        if(dist[i][j] != INF) return;
        dist[i][j] = d;
        q.emplace(i, j);
    };
    push(0, n-1, 0);
    while(q.size()) {
        auto[a, b] = q.front(); q.pop();
        for(auto na : to[a]) {
            for(auto nb : to[b]) {
                if(col[na] ^ col[nb]) push(na, nb, dist[a][b]+1);
            }
        }
    }
    int ans = dist[n-1][0];
    if(ans == INF) ans = -1;
    cout << ans << endl;
}

int main(){
    //set_time(__start__);
    alucrex al;
    int t; cin >> t;
    rep(i, t) solve();
    //set_time(__end__);
    //show_time(__start__ , __end__);
}

/*void solve() {
    alucrex al;
    int n, m; cin >> n >> m;
    vi col(n); al.vin(col);
    vvi to(n);
    rep(i, m) {
        int u, v; cin >> u >> v;
        u--, v--;
        to[u].emplace_back(v);
        to[v].emplace_back(u);
    }
    //BFS 歩数調整で足踏みも考慮しなきゃいけないのでこれじゃダメ
    //aokiとtakahashiのgoneを個別じゃなくてpairで判定しとけばよかったらしい
    vP gone(n, {0, 0});
    queue<P> q; q.push({0, n-1});
    int ans = 1;
    for( ; !q.empty() ; ans++) {
        P p = q.front(); q.pop();
        for(int to1 : to[p.first]) {
            if(gone[to1].first) continue;
            gone[to1].first = 1;
            for(int to2 : to[p.second]) {
                if(gone[to2].second) continue;
                gone[to2].second = 1;
                
                if(col[to1] ^ col[to2]) q.push({to1, to2});
            }
        }
        if(q.empty()) ans = -2;
    }
    cout << ans << endl;
}*/