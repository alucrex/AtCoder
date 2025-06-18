#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0 ; i < n ; i++)

int main() {
    int n; cin >> n;
    vector<string> a(n), b(n);
    for(auto & v : a) cin >> v;
    for(auto & v : b) cin >> v;

    rep(i, n) {
        rep(j, n) {
            if(a[i][j] == b[i][j]) continue;
            cout << i+1 << " " << j+1 << endl;
            return 0;
        }
    }
}