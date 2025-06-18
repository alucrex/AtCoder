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
};

int H,W;
bool field[16][16];
void des(int h, int w, int b, int a){
    cout << h << " " << w << " ■:" << b << " ■■:" << a << endl;
    rep(i,H+1){rep(j,W+1){
        cout << (field[i][j] ? "■" : "□");}cout << endl;
    }
}
ll dfs(int a, int b, int h, int w){//1*2の残り　1*1の残り  次に調べるマス[タテ][ヨコ]
    ll res = 0;
    if(w > W) w = 0, h++;
    // des(h,w,b,a);
    if(h == H && w == W){return 1;}
    // if(h > H){puts("ok");return 1;}

    if(!field[h][w]){
        field[h][w] = true;
        /*正方形のタイル*/
        if(b > 0){
            // line;puts("1");
            res += dfs(a,b-1,h,w+1);
        }
        
        /*ヨコ*/
        if(a > 0 && w+1 <= W && !field[h][w+1]){
            // line;puts("yoko");
            field[h][w+1] = true;
            res += dfs(a-1,b,h,w+1);
            field[h][w+1] = false;
        }
        /*タテ*/
        if(a > 0 && h+1 <= H){
            // line;puts("tate");
            field[h+1][w] = true;
            res += dfs(a-1,b,h,w+1);
            field[h+1][w] = false;
        }
        field[h][w] = false;
    }else res += dfs(a,b,h,w+1);
    
    // puts("back");
    return res;
}

int main(){
    alucrex al;
    int a,b;cin >> H >> W >> a >> b;
    H--;W--;
    cout << dfs(a,b,0,0) << endl; 
}