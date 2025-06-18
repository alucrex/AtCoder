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
#define v(n) vector<n>
#define vv(n) vector<vector<n>>
#define vvv(n) vector<vector<vector<n>>>
#define line cout << "================================" << endl;
#define Yn(x) cout << ((x) ? "Yes" : "No") << endl;
#define yn(x) cout << ((x) ? "yes" : "no") << endl;
#define mmax(a,b) a = max(a,b)
#define mmin(a,b) a = min(a,b)
#define debug(x) cout << #x" : " << (x) << endl;
#define output(x) cout << (x) << endl;
#define mod(n,x) (n) % (x)
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
#define evi 26
#define kani1 8
#define kani2 10
int main(){
    alucrex al;
    ll n;
    cin >> n;
    ll m = mod(n,evi);
    ll ans = 0;
    if(m != 0)for(ll i = 0 ; ; i++){
        ll r = evi*i+m;
        ll q1 = mod(evi*i + m , kani1), q2 = mod(evi*i + m, kani2);
        // debug(q1) debug(q2); line
        if(q1 == 0){
            ans = r/kani1;
            break;
        }
        if(mod(q1, kani2) == 0){
            ans = q1/kani2 + (r-q1)/kani1;
            break;
        }
        if(q2 == 0){
            ans = r/kani2;
            break;
        }
        if(mod(q2, kani1) == 0){
            ans = q2/kani1 + (r-q2)/kani2;
            break;
        }
    }
    cout << ans << endl;
    // m = evi*x+m = 8 or 10
}