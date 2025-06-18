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
const ll LINF = (1ll<<62) + ((1ll<<62)-1);
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
#define p_time(x) duration_cast<milliseconds>(x).count()
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
    void vvd(vv<T>& a){rep(i,a.size()){rep(j,a[i].size()){
        cout << a[i][j] << " ";}cout<<endl;
    }}
    bool TLE(steady_clock::time_point s, int time){
        steady_clock::time_point e = steady_clock::now();
        if(duration_cast<milliseconds>(e - s).count() >= time)return true;
        return false;
    }
};
vvi field;

struct graph {
    int x;
    int y;
    graph() {}
    graph(int a, int b) : y(a), x(b) {}
    graph operator+ (const graph& a) {
        return graph(this->y + a.y, this->x + a.x);
    }
    bool operator== (const graph& a) {
        return (this->y == a.y && this->x == a.x);
    }
};
int h, w;
v<graph> dir = {
    graph(-1, 0),
    graph(0, 1),
    graph(1, 0),
    graph(0, -1)
};

int dfs(graph p, graph s, vvi used) {
    alucrex al;
    used[p.y][p.x] = 1;
    
    int res = -1;
    for(auto u : dir) {
        graph to = p + u;
        int a = -1;
        if(to.x < 0 || to.y < 0 || to.x >= w || to.y >= h || field[to.y][to.x]) continue;

        if(to == s) a = 0;
        else if(used[to.y][to.x]) continue;
        else a = dfs(to, s, used);
        
        mmax(res, a);
    }
    if(res == -1) return -1;
    return res + 1;
}

int main(){
    //set_time(__start__);
    alucrex al;
    cin >> h >> w;
    field.resize(h);
    rep(i, h) {
        string s; cin >> s;
        for(auto c : s) field[i].push_back(c == '#');
    }

    int ans = 0;
    vvi used(h, vi(w, 0));
    rep(i, h) rep(j, w) mmax(ans, dfs(graph(i, j), graph(i, j), used));
    
    if(ans < 3) ans = -1;
    cout << ans << endl;
    //set_time(__end__);
    //show_time(__start__ , __end__);
}