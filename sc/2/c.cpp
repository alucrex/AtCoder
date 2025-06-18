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
#define debug(x) cout << #x" : " << x << endl;
#define ALL(n) (n).begin(),(n).end()

vi yakusu(int num){
    vi ans;
    for(int i = 1 ; i*i <= num ; i++){
        if(num % i == 0){
            ans.push_back(i);
            ans.push_back(num/i);
        }
    }
    sort(ALL(ans));
    return ans;
}

int main(){
    int a,b;
    cin >> a >> b;
    int m = 1;
    for(int i = b - a ; i >= 2 ; i--){
        int am = a % i;
        if(am == 0){
            m = i;
            break;
        }else{
            int d = i - am;
            if(b >= a + d + i){
                m = i;
                break;
            }
        }
    }
    cout << m << endl;
}