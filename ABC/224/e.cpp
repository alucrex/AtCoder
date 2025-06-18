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
int h, w;
vvi s, num;

int ei[] = {1, 0, -1, 0};
int ej[] = {0, 1, 0, -1};

void dfs(P e, int n = 0) {
    int y = e.first, x = e.second;
    if(num[y][x] && num[y][x] >= n) return ;
    num[y][x] = n;

    // debug(e);
    // alucrex al;
    // al.vvdes(num);

    rep(i, 4) {
        int tx = x + ei[i];
        int ty = y + ej[i];
        if(ty < 0 || tx < 0 || ty >= h || tx >= w) continue;
        if(s[ty][tx] >= s[y][x]) continue;

        dfs(m_p(ty, tx), n+1);
    }
}

int main(){
    //set_time(__start__);
    alucrex al;
    int n; cin >> h >> w >> n;
    s.resize(h, vi(w, 0));
    num.resize(h, vi(w, 0));
    vP g(n); //最後出力するときの
    v<pair<int, P>> mp(n); // a -> edge
    rep(i, n) {
        int r, c, a; cin >> r >> c >> a;
        r--, c--;
        s[r][c] = a;
        mp[i] = m_p(a, m_p(r, c));
        g[i] = m_p(r, c);
    }
    sort(rall(mp));
    // line;
    for(auto m : mp) {
        // cout << "       a : " << m.first << endl;
        dfs(m.second);
    }
    for(auto p : g) {
        cout << num[p.first][p.second] << endl;
    }
    //set_time(__end__);
    //show_time(__start__ , __end__);
}