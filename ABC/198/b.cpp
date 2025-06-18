#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rep1(i,n) for(int i = 1 ; i <= n ; i++)
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define rrep1(i,n) for(int i = n ; i > 0 ; i--)
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

int main(){
    ll num;
    cin >> num;
    if(num == 0){
        cout << "Yes" << endl;
        return 0;
    }
    while(num % 10 == 0){
        num /= 10;
    }
    string n = to_string(num);
    string right,left;
    for(ll l = 0 , r = n.size()-1 ; l <= r ; l++, r--){
        left += n[l];
        right += n[r];
        if(left != right){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}