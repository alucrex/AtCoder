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
        int intinput(){int a;cin >> a;return a;}
        ll llinput(){ll a;cin >> a;return a;}
        double dbinput(){double a;cin >> a;return a;}
        long double ldbinput(){long double a;cin >> a; return a;}
        string stinput(){string a;cin>>a;return a;}
};

#define AND 1
#define OR 0

int saikiY(vi&, int, int, int);
int saikiX(vi& a, int i, int type, int t){
    int ans = 0;
    if(i == 0){
        line;
        return 1;
    }
    ans += saikiY(a, i, false, t);
    ans += saikiY(a, i, true, t);
    return ans;
}

int saikiY(vi& a, int i, int type, int t){
    int ans = 0;
    if(t == true){
        if(a[i] == AND){
            if(type == false){
                return 0;
            }else if(type == true){
                ans += saikiX(a, i-1, true, true);
            }
        }else if(a[i] == OR){
            if(type == false){
                ans += saikiX(a, i-1, true, true);
            }else if(type == true){
                ans += saikiX(a, i-1, true, true) + saikiX(a, i-1, false, false);
            }
        }
    }else if(t == false){
        if(a[i] == AND){
            if(type == false){
                ans += saikiY(a, i-1, true, true) + saikiY(a, i-1, false, false);
            }else if(type == true){
                ans += saikiY(a, i-1, false, false);
            }
        }else if(a[i] == OR){
            if(type == false){
                ans += saikiY(a, i-1, false, false);
            }else if(type == true){
                return 0;
            }
        }
    }
    return ans;
}

int main(){
    alucrex al;
    int n = al.intinput();
    vi vec(n);//and->1 or->0
    rep(i,n){
        string x = al.stinput();
        if(x == "AND")vec[i] = 1;
        else vec[i] = 0;
    }
    int ans = saikiX(vec, n-1, true, true);
    //配列、どの位置を見るか、ひとつ上のタイプ、目標
    output(ans);
}