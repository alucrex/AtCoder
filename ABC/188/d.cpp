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
using p_q = priority_queue<int, vi, greater<int>>;
#define v(n) vector<n>
#define vv(n) vector<vector<n>>
#define vvv(n) vector<vector<vector<n>>>
#define p_q(n) priority_queue<n, v(n), greater<n>>
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
};

struct snuke{
    int s;//start
    int e;//end
    int p;//price
};
bool operator<(const snuke& a, const snuke& b){
    if(a.s == b.s){
        return a.e < b.e;
    }
    return a.s < b.s;
}
bool operator>(const snuke& a, const snuke& b){
    if(a.s == b.s){
        return a.e > b.e;
    }
    return a.s > b.s;
}

int main(){
    alucrex al;
    int n;
    ll snuke_prime;cin >> n >> snuke_prime;
    p_q(P) q;
    p_q(P) start;
    p_q(P) end;
    rep(i,n){
        int a, b, price;
        cin >> a >> b >> price;
        q.push(make_pair(a,price));
        q.push(make_pair(b+1,price * -1));

    }
    
    ll ans = 0;

    int beforedate = 0;
    ll np = 0;
    while(q.size()){
        ans += (q.top().first - beforedate) * min(np, snuke_prime);
        np += q.top().second;
        beforedate = q.top().first;
        q.pop();
    }
    cout << ans << endl;
}