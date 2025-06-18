#include <bits/stdc++.h>//AC
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int main(){
    int N;
    cin >> N;
    set<int> ans;
    rep(i, N){
        int snuke_p;
        int snuke_t;
        int snuke_x;
        cin >> snuke_t >> snuke_p >> snuke_x;
        if(snuke_t < snuke_x)ans.insert(snuke_p);
    }
    cout << ((ans.size() == 0) ? -1 : *begin(ans)) << endl;
}
