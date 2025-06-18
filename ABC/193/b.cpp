#include <bits/stdc++.h>//AC
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int main(){
    int N;
    cin >> N;
    vector<int> snuke_p(N);
    vector<int> snuke_t(N);
    vector<int> snuke_x(N);
    set<int> ans;
    rep(i, N){
        cin >> snuke_t[i] >> snuke_p[i] >> snuke_x[i];
        if(snuke_t[i] < snuke_x[i])ans.insert(snuke_p[i]);
    }
    cout << ((ans.size() == 0) ? -1 : *begin(ans)) << endl;
}
