#include <bits/stdc++.h>//解説見た
using namespace std;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rep1(i,n) for(int i = 1 ; i < n ; i++)
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i++)
#define INF 1001001001
using ll = int64_t;
using P = pair<int, int>;

struct bag{
    ll w =0;
    ll p = 0;
};

int main(){
    int n, w;
    cin >> n >> w;
    vector<bag> b(n);
    rep(i, n)cin >> b.at(i).w >> b.at(i).p;
    vector<vector<ll>> s(n, vector<ll>(w+1, 0));
    rep(i, n)rep(j, w+1){
        // cout << i << " , " << j << "\t : ";
        if(i == 0){
            if(b.at(i).w <= j)s.at(i).at(j) = b.at(i).p;
        }else if(j - b.at(i).w < 0){
            s.at(i).at(j) = s.at(i-1).at(j);
            // cout << s.at(i).at(j)  << " = " << s.at(i-1).at(j) << endl;
        }else{
            s.at(i).at(j) = max(s.at(i-1).at(j), s.at(i-1).at(j-b.at(i).w) + b.at(i).p);
            // cout << s.at(i).at(j) << " = max" << s.at(i-1).at(j) << " , " << s.at(i-1).at(j-b.at(i).w) + b.at(i).p << endl;
        }
    }
    cout << s.at(n-1).at(w) << endl;
}