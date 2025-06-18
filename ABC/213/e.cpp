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
};

vP direct = {
    make_pair(1, 0),
    make_pair(-1, 0),
    make_pair(0, 1),
    make_pair(0, -1)
};
vP directx = {
    make_pair(0, 0),
    make_pair(1, 0),
    make_pair(-1, 0),
    make_pair(0, 1),
    make_pair(0, -1),
    make_pair(1, 1),
    make_pair(-1, 1),
    make_pair(1, -1),
    make_pair(-1, -1)
};

P operator+ (const P& a, const P& b) {
    return make_pair(a.first+b.first , a.second+b.second);
}

int main(){
    //set_time(__start__);
    alucrex al;
    int h, w; cin >> h >> w;
    vector cost(h, vi(w, INF));
    vector field(h, vi(w));
    rep(i, h) {
        string s; cin >> s;
        rep(j, w) {
            field[i][j] = (s[j] == '#');
        }
    }

    //01bfs
    deque<P> dq; vector used(h, vi(w, 0));
    dq.emplace_front(0, 0);
    cost[0][0] = 0;
    while(!dq.empty()) {
        auto p = dq.front(); dq.pop_front();
        int nc = cost[p.first][p.second];
        if(used[p.first][p.second]) continue;
        used[p.first][p.second] = 1;

        // debug(p);
        for(auto d : direct) {
            auto [i, j] = p + d;
            if(i < 0 || j < 0 || i >= h || j >= w) continue;
            
            if(field[i][j]) {
                for(auto ed : directx) {
                    auto [ei, ej] = make_pair(i, j) + ed;
                    if(ei < 0 || ej < 0 || ei >= h || ej >= w) continue;
                    if(cost[ei][ej] > nc + 1) {
                        dq.emplace_back(ei, ej);
                        cost[ei][ej] = nc + 1;
                        // cout << ei << " , " << ej << " = " << nc + 1 << endl;
                    }
                }
            } else {
                if(cost[i][j] > nc) {
                    dq.emplace_front(i, j);
                    cost[i][j] = nc;
                    // cout << i << " , " << j << " = " << nc << endl;
                }
            }
        }
    }
    al.vvdes(cost);
    cout << cost[h-1][w-1] << endl;

    //set_time(__end__);
    //show_time(__start__ , __end__);
}