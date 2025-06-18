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
#define dall(a) (a).rbegin(),(a).rend()

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

struct q{
    int x = 0;
    int y = 0;
    int z = 0;
};
bool operator< (const q & a, const q & b){
    if(a.x == b.x){
        if(a.y == b.y){
            return a.z < b.z;
        }
        return a.y < b.y;
    }
    return a.x < b.x;
}
bool operator> (const q & a, const q & b){
    if(a.x == b.x){
        if(a.y == b.y){
            return a.z > b.z;
        }
        return a.y > b.y;
    }
    return a.x > b.x;
}

// <x , >y, z> -->より強い条件
int main(){
    alucrex al;
    int n, m; cin >> n >> m;
    vi vec(n);
    rep1(i,n)vec[i-1] = i;
    vector<q> quer(m);
    rep(i,m){
        cin >> quer[i].x >> quer[i].y >> quer[i].z;
    }
    sort(dall(quer));
    vi jogai;
    rep1(i,m-1){
        if(quer[i-1].x < quer[i].x && quer[i-1].y > quer[i].y && quer[i-1].z < quer[i].z){
            jogai.push_back(i);
        }
    }

    ll ans = 0;
    rep(i,1<<n){
        int cnt = 0;
        rep(j,n){

        }
    }
}