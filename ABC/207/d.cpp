#include <bits/stdc++.h>
using namespace std;
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

bool judge();
struct graph {
    int x;
    int y;
};
int f(int n) {return n*n;}
int dis(graph a, graph b) {
    return f(a.x-b.x) + f(a.y-b.y);
    }
using vg = vector<graph>;
vg s, t;
int n;
int main(){
    alucrex al;
    cin >> n;
    s.resize(n); t.resize(n);
    rep(i,n) {
        cin >> s[i].x >> s[i].y;
    }
    rep(i,n) {
        cin >> t[i].x >> t[i].y;
    }
    rep(cnt,4) {
        rep(i,n) {
            int x,y;
            s[i].x = x, s[i].y = y;
            s[i].x = -y, s[i].y = x;
        }
        for(auto ss : s) cout << ss.x << " , " << ss.y << endl;
        if(judge()) {
            cout << Yn(1) << endl;
            return 0;
        }line
    }
    cout << Yn(0) << endl; 
    return 0;
}

bool judge() {
    vg s_(n);
    rep(i,n) s_[i] = s[i];
    int symax = -40, tymax = -40;
    rep(i,n) {
        mmax(symax, s[i].y);
        mmax(tymax, t[i].y);
    }
    rep(i,n) {
        s_[i].x -= 100;
        s_[i].y += tymax-symax;
    }
    int d = dis(s_[0], t[0]);
    rep(i,n) {
        // debug(dis(s_[i],t[i]));
        if(d != dis(s_[i], t[i])) return false;
    }
    return true;
}