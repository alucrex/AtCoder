#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define EXPENTION_0(n) if(n == 0)break;
#define EXPENTION_END(n,e) if(x == e - 1)break;

int main(){
    int h, w, x, y;
    cin >> h >> w >> y >> x;
    vector<vector<int>> cood(h, vector<int>(w, -1));
    rep(i, h){
        string s;
        cin >> s;
        rep(j, s.size()){
            if(s.at(j) == '#')cood.at(i).at(j) = 1;
            if(s.at(j) == '.')cood.at(i).at(j) = 0;
        }
    }
    int ans = 0;

    for(int i = x - 1; i >= 0 ; i--){//ヨコ ←←
        if(cood.at(y - 1).at(i) == 1)break;
        ans++;
    }
    for(int i = x - 1 ; i < w ; i++){//ヨコ→→
        if(cood.at(y - 1).at(i) == 1)break;
        ans++;
    }
    for(int i = y - 1 ; i >= 0 ; i--){//タテ↑↑
        if(cood.at(i).at(x - 1) == 1)break;
        ans++;
    }
    for(int i = y - 1 ; i < h ; i++){//タテ↓↓
        if(cood.at(i).at(x - 1) == 1)break;
        ans++;
    }
    cout << ans - 3 << endl;
}