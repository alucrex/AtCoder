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

vvi field;
int r, c;
int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};

void dfs(int x, int y,int pw, int dist = 0,  vvi gone = vvi(r, vi(c, 0))) {
    if(dist > pw) return;
    field[x][y] = 0;
    rep(i, 4) {
        int ni = x + di[i];
        int nj = y + dj[i];
        if(ni < 0 || nj < 0 || ni >= r || nj >= c) continue;
        if(gone[ni][nj]) continue;
        gone[ni][nj] = 1;
        dfs(ni, nj, pw, dist+1, gone);
    }
}

int main(){
    //set_time(__start__);
    alucrex al;
    struct bm {
        int x;
        int y;
        int pw;
        bm(int xx, int yy, int pp) {
            x = xx;
            y = yy;
            pw = pp;
        }
    };
    cin >> r >> c;
    field.resize(r, vi(c, 0));
    v<bm> bomb;
    rep(i, r) {
        string s; cin >> s;
        rep(j, c) {
            if(s[j] == '#') field[i][j] = 1;
            if(s[j] == '.') field[i][j] = 0;
            else bomb.emplace_back(bm(i, j, s[j]-'0'));
        }
    }
    for(auto f : bomb) {
        dfs(f.x, f.y, f.pw);
    }
    for(auto v : field) {
        for(auto c : v) {
            if(c) cout << "#";
            else cout << ".";
        }
        puts("");
    }
    //set_time(__end__);
    //show_time(__start__ , __end__);
}