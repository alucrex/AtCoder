#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < (n) ; i++)
#define rep1(i,n) for(int i = 1 ; i <= (n) ; i++)
#define rrep(i,n) for(int i = (n) - 1 ; i >= 0 ; i--)
#define rrep1(i,n) for(int i = (n) ; i > 0 ; i--)
#define INF 1001001001
#define MOD 1000000007
using ll = int64_t;
using P = pair<int, int>;
using PL = pair<ll,ll>;
using PD = pair<double,double>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using vP = vector<P>;
using p_q = priority_queue<int, vi, greater<int>>;
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
#define mod(n,x) ((n)%(x))
#define all(a) (a).begin(),(a).end()

class alucrex{
    public:
    void vin(vi& a){rep(i,a.size())cin>>a[i];}
    void vvin(vvi& a){rep(i,a.size())rep(j,a[i].size())cin>>a[i][j];}
    void vvdes(vvi& a){rep(i,a.size()){rep(j,a[i].size()){
        cout << a[i][j] << " ";}cout<<endl;
    }}
    void vinl(vl& a){rep(i,a.size())cin>>a[i];}
    void vvinl(vvl& a){rep(i,a.size())rep(j,a[i].size())cin>>a[i][j];}
    void vvdesl(vvl& a){rep(i,a.size()){rep(j,a[i].size()){
        cout << a[i][j] << " ";}cout<<endl;
    }}
    void vpin(vP& a){for(auto & x : a)cin>>x.first>>x.second;}
};

int min4(int a, int b, int c, int d){
    return (a<b ? a : (b<c ? b : (c<d ? c : d)));
}

int main(){
    alucrex al;
    int n; cin >> n;
    vvi cood(n+1);
    rep(i,n){
        P p;
        cin >> p.first >> p.second;
        cood[p.second].push_back(p.first);
    }
    vvi ball;
    ball.push_back({0,0,0});
    rep1(i,n){
        int Max = -INF, Min = INF;
        rep(j,cood[i].size()){
            mmax(Max,cood[i][j]);
            mmin(Min,cood[i][j]);
        }
        if(Min != INF)ball.push_back({Min,Max,abs(Max-Min)});
    }
    vvl dp;
    dp.push_back({0,0});
    ll ans = 0;
    int now = 0;
    rep1(i,ball.size()-1){
        if(ball[i][0] == INF)continue;
        ll dp0, dp1;
        //dp[i][0]
        dp0 = min(  dp.back()[0] + abs(ball[i-1][0] - ball[i][1]),
                    dp.back()[1] + abs(ball[i-1][1] - ball[i][1])) + ball[i][2];
        //dp[i][1]
        dp1 = min(  dp.back()[0] + abs(ball[i-1][0] - ball[i][0]),
                    dp.back()[1] + abs(ball[i-1][1] - ball[i][0])) + ball[i][2];
        dp.push_back({dp0,dp1});
        if(dp0 <0 || dp1 < 0){
            cout << i << endl;
            cout << "dam"<< endl;
            return 0;
        }
        now = dp0 <= dp1 ? ball[i][0] : ball[i][1];
    }
    ans = min(dp.back()[0], dp.back()[1]) + abs(now);
    cout << ans << endl;
}