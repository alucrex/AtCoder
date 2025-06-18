#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
#define rep(i,n) for(int i = 0 ; i < (n) ; i++)
#define rep1(i,n) for(int i = 1 ; i <= (n) ; i++)
#define rrep(i,n) for(int i = (n) - 1 ; i >= 0 ; i--)
#define rrep1(i,n) for(int i = (n) ; i > 0 ; i--)
#define MOD 998244353 
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
    ll rui(ll n, int r, int m = 1) {
        ll res = 1;
        for(int i = 0 ; i < r ; i++) {res *= n; res %= m;}
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

void dpset(vl& dp) {
    ll n = 1;
    for(auto& d : dp) {
        d = n;
        n *= 2;
        n %= MOD;
    }
}

int main(){
    //set_time(__start__);
    alucrex al;
    int n, d; cin >> n >> d;
    ll ans = 0;
    vl dp(d+1); //下向きにi段下がったとき(2^i)
    dpset(dp);

    ll shita = al.rui(2, d-1, MOD); //n+d段目の頂点数
    ll ndanme = 1; //n段目の頂点数
    ll ue = 1; // n-d段目の頂点数
    rep1(i, n) { //i段目
        // ans += al.rui(2, d, MOD);
        // int log;
        // for(int j = 0 ; al.rui(2,j) )

        /*下*/
        rep(j, min(i, d-1))
        if(n-d >= i){
            ans += (shita * ndanme) % MOD;
            ans %= MOD;
            ndanme *= 2; ndanme %= MOD;
            shita *= 2; shita %= MOD;
        }

        /*上*/
        if(d <= i) {
            ans += (ue * ndanme) % MOD;
            ans %= MOD;
            ndanme *= 2; ndanme %= MOD;
            ue *= 2; ue %= MOD;
        }
    }
    cout << ans << endl;
    //set_time(__end__);
    //show_time(__start__ , __end__);
}