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
#define mOd 998244353

ll cul(ll a,char s, ll b){
    ll res = 0;
    if(s == '*'){
        res = mod(a,mOd) * mod(b,mOd);
        res = mod(res, mOd);
    }else if(s == '/'){
        if(a % b != 0){
            for(int i = 0 ; a % b != 0 ; i++){
                a += mOd * i;
            }
        }
        if(b == 0){
            cout << "xxxxxxx" << endl;
            return -1;
        }
        res = a / b;
    }
    return res;
}

ll rui(int n, int k){
    //n^k
    ll res = 1;
    rep(i,k){
        res *= n;
        res %= mOd;
    }
    return res;
}

ll combe(int a, int b){
    ll res = 1;
    ll waru = 1;
    rep(i,b){
        res *= a-i;
        waru *= i+1;
        res %= mOd;
        waru %= mOd;
    }
    if(waru == 0){
        cout << "xxxxxxxxx" << endl;
        return -1;
    }
    res = cul(res, '/', waru);
    res %= mOd;
    return res;
}

int main(){
    alucrex al;
    int n, k;
    cin >> n >> k;
    ll ans;
    ans = rui(n*2,k);
    for(int i = k - 1 ; i > 0 ; i--){
        ans -= cul(rui(i,n*2), '*', combe(k,i));
    }
    cout << ans << endl;
}