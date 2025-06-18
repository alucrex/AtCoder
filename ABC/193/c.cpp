#include <bits/stdc++.h>//AC
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int main(){
    ll N;
    cin >> N;
    set<ll> ans;
    for(ll i = 2 ; i * i <= N ; i++){
        for(ll j = 2 ; pow(i, j) <= N ; j++){
            ans.insert(pow(i, j));
        }
    }
    cout << N - ans.size() << endl;
}