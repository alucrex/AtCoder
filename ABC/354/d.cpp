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
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x" : " << (x) << endl;
#else
#define debug(x) x;
#endif
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

int isIn(int a, int b) { // yoko = 0 de ok
    for(int i = a ; i <= b ; i++) if((i%4+4)%4 == 0) return true;
    return false;
}

int main(){
    //set_time(__start__);
    alucrex al;
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ll tate = d/2 - b/2;
    ll yoko = c/4 - a/4;
    ll ans = tate*yoko*8;
    if(d&1) ans += yoko*4;
    if(b&1) ans += yoko*4;

    if((c%4+4)%4==1) ans += tate*3;
    if((c%4+4)%4==2) ans += tate*6;
    if((c%4+4)%4==3) ans += tate*7;
    if((a%4+4)%4==3/*-1*/) ans += tate*1;
    if((a%4+4)%4==2/*-2*/) ans += tate*2;
    if((a%4+4)%4==1/*-3*/) ans += tate*5;
    debug(ans);
    if(d&1 && (c%4+4)%4 == 1) ans += 2; 
    if(d&1 && (c%4+4)%4 == 2) ans += 3;
    if(d&1 && (c%4+4)%4 == 3) ans += 3;
    if(d&1 && (a%4+4)%4 == 3/*-1*/) ans += 1;
    if(d&1 && (a%4+4)%4 == 2/*-2*/) ans += 1;
    if(d&1 && (a%4+4)%4 == 1/*-3*/) ans += 2;
    debug(ans)
    if(b&1 && (c%4+4)%4 == 1) ans += 1; 
    if(b&1 && (c%4+4)%4 == 2) ans += 3;
    if(b&1 && (c%4+4)%4 == 3) ans += 4;
    if(b&1 && (a%4+4)%4 == 3/*-1*/) ans += 0;
    if(b&1 && (a%4+4)%4 == 2/*-2*/) ans += 1;
    if(b&1 && (a%4+4)%4 == 1/*-3*/) ans += 3;

    if(yoko == 0 && !isIn(a, c)) {
        ans = 0;
        int mc = (c%4+4)%4, ma = (a%4+4)%4;

        if(ma<= 1 && 1 < mc) ans += tate*3;
        if(ma<= 2 && 2 < mc) ans += tate*1;
        debug(ans);
        if(d&1 && ma<= 1 && 1 < mc) ans += 1;
        if(d&1 && ma<= 2 && 2 < mc) ans += 0;
        debug(ans)
        if(b&1 && ma<= 1 && 1 < mc) ans += 2;
        if(b&1 && ma<= 2 && 2 < mc) ans += 1;
    }
    debug(tate)
    debug(yoko)
    cout << ans << endl;
    // rep(i, 21) {
    //     cout << i-10 << " : " << (i-10)%2 << endl;
    // }
    //set_time(__end__);
    //show_time(__start__ , __end__);
}