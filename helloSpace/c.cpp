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

int min5(int a,int b,int c,int d,int e){
    int ans;
    ans = min(d,e);
    mmin(ans,c);
    mmin(ans,b);
    mmin(ans,a);
    return ans;
}

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
    void vpin(vP& a){for(auto& x:a)cin>>x.first>>x.second;}
template<typename T>
void vvd(vv(T)& a){rep(i,a.size()){rep(j,a[i].size()){
    cout << a[i][j] << " ";}cout<<endl;
}}

P f1(vi vec){
    int ans = INF;
    int ind;
    rep(i,vec.size()){
        if(ans > vec[i])ind = i;
        mmin(ans,vec[i]);
    }
    return make_pair(ans,ind);
}

int main(){
    alucrex al;
    int n; cin >> n;
    vvi abi(n,vi(5,0));al.vvin(abi);
    vi Min;
    vi ind(5);
    vvi am(5);
    rep(i,5){
        vP vec;
        rep(j,n){
            vec.push_back(make_pair(abi[j][i],j));
            
        }
        sort(all(abi));
        vec.erase(vec.begin()+3,vec.end());
        ami[i] =
    }
    int ans = INF;
    rep(i,5){
        mmin(ans,f1(abi[i]).first);
    }
    cout << ans << endl;
}