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
template<typename T> using v = vector<T>;
template<typename T> using vv = vector<vector<T>>;
template<typename T> using vvv = vector<vector<vector<T>>>;
template<typename T> using p_q = priority_queue<T, v<T>, greater<T>>;
const int INF = 1001001001;
const ll LINF = (1ll<<62); //+ ((1ll<<62)-1);
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
    ll rui(int n, int r) {
        ll res = 1;
        for(int i = 0 ; i < r ; i++) res *= n;
        return res;
    }
    ll rui(ll n, int r) {
        ll res = 1;
        for(int i = 0 ; i < r ; i++) res *= n;
        return res;
    }
    ll kai(int n) { //O(N)
        ll res = 1;
        for(int i = 2 ; i <= n ; i++) res *= i;
        return res;
    }
    ll kai(ll n) {
        ll res = 1;
        for(int i = 2 ; i <= n ; i++) res *= i;
    return res;
    }
};

struct unionFind {
    vector<int> par;

    int root(int x) {
        if(par[x] == -1) return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if(x != y) par[x] = y;
    }
    bool is_same(int x, int y) {
        return root(x) == root(y);
    }
    unionFind(int x) : par(x, -1) {}
};

int main(){
    //set_time(__start__);
    alucrex al;
    int n, m; cin >> n >> m;
    unionFind uf(n);
    v<pair<int, P>> edge;
    ll ans = 0;
    rep(i, m) {
        int u, v, p; cin >> u >> v >> p;
        u--, v--;
        if(p < 0) {
            uf.unite(u, v);
            continue;
        }
        edge.emplace_back(p, m_p(u, v));
        ans += (ll)p;
    }

    sort(all(edge));

    for(auto& e : edge) {
        int& p = e.first;
        int u = e.second.first, v = e.second.second;
        if(uf.is_same(u, v)) continue;
        
        uf.unite(u, v);
        ans -= (ll)p;
    }
    cout << ans << endl;


    //set_time(__end__);
    //show_time(__start__ , __end__);
}