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

int main(){
    int n, m, k;
    cin >> n >> m;
    vector<int> a(m,0);
    vector<int> b(m,0);
    rep(i,m)cin >> a[i] >> b[i];
    cin >> k;
    vector<int> c(k,0);
    vector<int> d(k,0);
    rep(i,k)cin >> c[i] >> d[i];

    int ans = -INF;
    rep(bit, 1<<k){//O(2^k)
        set<int> field;
        
        rep(i,k){//O(k)
        if(bit>>i&1)field.insert(c[i]);
        else field.insert(d[i]);
        }

        int ten_ans = 0;
        rep(i, m){
            if(field.count(a[i]) && field.count(b[i]))ten_ans++;
        }
        ans = max(ans, ten_ans);
    }
    cout << ans << endl;
}