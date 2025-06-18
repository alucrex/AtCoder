#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rep1(i,n) for(int i = 1 ; i < n ; i++)
#define rrep(i,n) for(int i = n -1; i >= 0 ; i++)
#define INF 1001001001
using ll = int64_t;
using P = pair<int, int>;
int mod(int);

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i, n )cin >> h[i];
    vector<ll> s(n, INF);
    s[0] = 0;

    for(int i = 1; i < n ; i++){
        for(int j = 1 ; i - j >= 0 && j <= k ; j++){
            s[i] = (ll)min(s[i],  s[i - j] + mod(h[i] - h[i - j]));
        }
    }
    cout << s[n - 1] << endl;
}

int mod(int n){
    if(n < 0)n *= -1;
    return n;
}