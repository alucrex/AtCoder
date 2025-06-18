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


int judge(int a, int b) { //左がかったとき１を返す あいこのとき０　右がかったとき２
    if(a == 0) {
        switch(b) {
            case 0 : return 0;
            case 1 : return 1;
            case 2 : return 2;
        }
    }
    if(a == 1) {
        switch(b) {
            case 0 : return 2;
            case 1 : return 0;
            case 2 : return 1;
        }
    }
    if(a == 2) {
        switch(b) {
            case 0 : return 1;
            case 1 : return 2;
            case 2 : return 0;
        }
    }
}

int main(){
    //set_time(__start__);
    alucrex al;
    int n, m; cin >> n >> m;
    vvi hand(2*n, vi(m));
    vP pq(2*n), pq1; //(勝数、番号)
    rep(i, 2*n) pq[i] = m_p(0, i);
    for(auto& x : hand) {
        string s; cin >> s;
        rep(i, m) {
            int c;
            if(s[i] == 'G') c = 0;
            else if(s[i] == 'C') c = 1;
            else c = 2;
            x[i] = c;
        }
    }

    rep(i, m) {
        rep(j, n) {
            auto a = pq[2*j];
            auto b = pq[2*j+1];
            int result = judge(hand[a.second][i], hand[b.second][i]);

            if(result == 1) a.first++;
            else if(result == 2) b.first++;
            pq1.emplace_back(a);
            pq1.emplace_back(b);
            
        }
        sort(all(pq1), [](const P& a, const P& b) {
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });
        swap(pq, pq1);
        pq1.clear();
    }
    for(auto i : pq) cout << i.second+1 << "\n";
    
    //set_time(__end__);
    //show_time(__start__ , __end__);
}