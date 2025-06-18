#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int main(){
    ll N =0;
    cin >> N;
    ll ans=0;
    for(ll i =1000 ; i <= N ; i*=1000){
        ans += N - i + 1;
    }
    cout << ans << endl;
}