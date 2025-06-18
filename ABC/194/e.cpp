#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rep1(i,n) for(int i = 1 ; i < n ; i++)
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
#define line cout << "=====================" << endl;


int main(){
    int n, m;
    cin >> n >> m;
    vvi a(n,vi(1,-1));
    int w = n - m;
    rep(i,n){
        int x;
        cin >> x;
        a[x].push_back(i);
    }
    rep(i,n){//mexにiがあるか
        bool ok = true;
        a[i].push_back(n);
        rep1(k,a[i].size())if(a[i][k] - a[i][k-1] > m){
            cout << i << endl;
            return 0;
        }
    }
    cout << n << endl;
}