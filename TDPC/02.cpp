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
#define p_time(x) duration_cast<milliseconds>(x).count()
#define show_time(s, e) cout << "実行時間" << duration_cast<milliseconds>(e-s).count() << "ms\n"
template <typename T> void chmin(T& a, T b){if(a>b)a=b;}
template <typename T> void chmax(T& a, T b){if(a<b)a=b;}
template <typename t> using pq = priority_queue<t, v(t), greater<t>>;

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
        bool TLE(steady_clock::time_point s, int time){
        steady_clock::time_point e = steady_clock::now();
        if(duration_cast<milliseconds>(e - s).count() >= time)return true;
        return false;
    }
};

int main(){
    //set_time(__start__);
    alucrex al;
    int n; cin >> n;
    int bit = n;
    p_q q;
    rrep1(bt,1<<(n+1)-1) {
        string s;
        int l_ = 0 , _l = 0;
        bool flag = false;
        rep(j, n) {
            if(bt>>(n-j-1) & 1) _l++;
            else l_++;
            if(l_ < _l) {
                flag = true;
                break;
            }
        }
        if(flag || l_ != _l)continue;
        q.push(bt);
    }
    while(!q.empty()) {
        auto qu = q.top(); q.pop();
        rep(j,n) {
            if(qu>>(n-j-1) & 1)cout << ")";
            else cout << "(";
        }cout << qu << endl;
    }
    //set_time(__end__);
    //show_time(__start__ , __end__);
}