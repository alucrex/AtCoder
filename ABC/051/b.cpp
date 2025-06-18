#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int main(){
    int k, s;
    cin >> k >> s;
    int ans = 0;
    rep(x, k+1)
        rep(y, k+1){
            if(s - x - y < 0)break;
            if(s - x - y <= k)ans++;
        }
    cout  << ans << endl;
}