#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int main(){
    int N;
    cin >> N;
    vector<int> vec(N,0);
    vector<int> s(N, 0);
    ll ans = 0;
    rep(i, N){
        cin >> vec[i];
        if(i == 0)s[i] = vec[i];
        s[i] = s[i-1] + vec[i];
    }
    for(int i = N - 1 ; i >= 0 ; i--){
        ans += (N - 1) * pow(vec[i], 2) - 2 * vec[i] * (s[i] -vec[i]);
        cout << "N - 1 * " << vec[i] << " ^ 2 - 2 * " << vec[i] << "( " << s[i] << " - " << vec[i] << " )" << endl;
    }
    cout << ans << endl;
}