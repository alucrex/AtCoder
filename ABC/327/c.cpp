#include <bits/stdc++.h>
#include <chrono>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < (n) ; i++)
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define Yn(x) ((x) ? "Yes" : "No")
#define debug(x) cout << #x" : " << (x) << endl;

int main() {
    int n = 9;
    vvi field(n, vi(n, 0));

    vi cnt(n, 0);
    int t = 1;
    rep(i, n) {
        rep(j, n) {
            cin >> field[i][j]; field[i][j]--;

            cnt[field[i][j]]++;
            if(cnt[field[i][j]] > t) {
                cout << Yn(0) << endl;
                return 0;
            }
        }
        t++;
    }
    rep(i, n) {
        rep(j, n) {
            cnt[field[j][i]]++;
            if(cnt[field[j][i]] > t) {
                cout << Yn(0) << endl;
                return 0;
            }
        }
        t++;
    }
    rep(i, n) {
        rep(j, n) {
            int ni = i/3*3 + j/3;
            int nj = i%3*3 + j%3;
            cnt[field[ni][nj]]++;
            if(cnt[field[ni][nj]] > t) {
                cout << Yn(0) << endl;
                return 0;
            }
        }
        t++;
    }
    cout << Yn(1) << endl;
}