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
#define all(a,b) (a).begin(),(b).end()

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


int main(){
    alucrex al;
    int h, w; cin >> h >> w;
    vvi field(h,vi(w));
    rep(i,h){
        string s; cin >> s;
        int j = 0;
        for(char c : s)field[i][j++] = (c == '.' ? 0 : 1);
    }
    int ans = 0;
    rep(i,h-1)rep(j,w-1){
        vvi grid(2, vi(2));
        int color = field[i][j] + field[i+1][j] + field[i][j+1] + field[i+1][j+1];
        switch(color) {
            case 1 :
            case 3 : 
                ans++;
                break;
        }
    }
    cout << ans << endl;
}