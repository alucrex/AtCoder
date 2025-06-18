#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
int mod(int);

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n )cin >> h[i];
    vector<ll> s(n);
    s[0] = 0;
    for(int i = 1; i < n ; i++){
        if(i == 1) s[1] = mod(h[0] - h[1]);
        s[i] = (ll)min( s[i - 1] + mod(h[i - 1] - h[i]),
                    s[i - 2] + mod(h[i - 2] - h[i]));
    }
    cout << s[n - 1] << endl;
}

int mod(int n){
    if(n < 0)n *= -1;
    return n;
}