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
int n; vvi to;
int main(){
    set_time(__start__);
    alucrex al;
    int querry; cin >> n >> querry;
    to.resize(n+1);
    vvi rto(n+1, vi(n+1, 0));
    vvi dp(n+1, vi(n+1, 0)); // i < j
    rep(i, n-1) {
        int f, t; cin >> f >> t;
        to[f].push_back(t);
        rto[f].push_back(t);
        rto[t].push_back(f);
    }
    //bfs
    rep1(i, n) {
        int score = 1;
        queue<int>que, que1; for(int u : to[i])que1.push(u);
        for(int j = 0 ; !que.empty() || !que1.empty() ; j++, score++) {
            if(j%2)while(!que.empty()) {

                int q = que.front(); que.pop();debug(q);
                dp[i][q] += score;
                for(int u : to[q])que1.push(u);

            }else while(!que1.empty()) {

                int q = que1.front(); que1.pop();debug(q);
                dp[i][q] += score;
                for(int u : to[q])que.push(u);
            }
        }
    }
    al.vvdes(dp);

    rep(i, querry) {
        int a, b; cin >> a >> b;
        int flag = 0;
        vvi used(n+1, vi(n+1, 0));
        queue<int> qa, qb, qa_, qb_;
        for(int u : rto[a])qa.push(u);
        for(int u : rto[b])qb.push(u);
        for(int j = 0 ; ; j++) {
            rep(k, qa.size()) {
                int q1 = qa.front(); qa.pop(); qa.push(q1);
                rep(l, qb.size()) {
                    int q2 = qb.front(); qa.pop(); qa.push(q2);
                    if(q1 == q2) {
                        cout << "Road" << endl;
                        flag = 1;
                    }if(q1 < q2 && dp[q1][q2]) {
                        cout << (dp[q1][q2]%2 ? "Town" : "Road") << endl;
                        flag = 1;
                    }else if(dp[q2][q1]) {
                        cout << (dp[q2][q1]%2 ? "Town" : "Road") << endl;
                        flag = 1;
                    }
                    if(flag)break;
                }
                if(flag)break;
            }
            if(flag)break; 
            while(!qa.empty()) {
                int q = qa.front(); qa.pop();
                for(int u : rto[q]) {
                    if(used[u][q] && used[q][u]){
                        qa_.push(u);
                    }
                    used[u][q] = 1;
                    used[q][u] = 1;

                }
            }
            while(!qb.empty()) {
                int q = qb.front(); qb.pop();
                for(int u : rto[q]) {
                    if(used[u][q] && used[q][u]) {
                        qb_.push(u);
                    }
                    used[u][q] = 1;
                    used[q][u] = 1;
                }
            }
            while(!qa_.empty()) {
                qa.push(qa_.front());
                qa_.pop();
            }
            while(!qb_.empty()) {
                qb.push(qb_.front());
                qb_.pop();
            }

            al.TLE(__start__, 2000);
        }
    }

    //set_time(__end__);
    //show_time(__start__ , __end__);
}