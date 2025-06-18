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
#define Yn(x) cout << ((x) ? "Yes" : "No" << endl;
#define yn(x) cout << ((x) ? "yes" : "no" << endl;


#define endd cout << "UNSOLVABLE" << endl;\
return 0;
int main(){
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int k1 = s1.size(), k2 = s2.size(), k3 = s3.size();
    if(s1 == s2 && s2 == s3){
        if(k1 == 1){
            cout << 0 << endl<< 0<< endl << 0<< endl;
            return 0;
        }else endd
    }
    if(k3 < k2 || k3 < k1)endd
    if(k1 + 2 <= k3 && k2 + 2 <= k3)endd
    set<char> s;
    rep(i,s1.size())s.insert(s1[i]);
    rep(i,s2.size())s.insert(s2[i]);
    rep(i,s3.size())s.insert(s3[i]);
    
}