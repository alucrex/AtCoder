#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
ll keta(ll);
ll g1(ll);

int main(){
    int n, k;
    cin >> n >> k;
    cout << g1(n) << endl;

}

ll keta(ll num){
    std::string s = std::to_string(num);
    return s.size();
}

ll g1(ll num){
    int k = keta(num);
    priority_queue<int> n;
    string s = to_string(num);
    for(int i = 0 ; i < s.size() ; i++){
        n.push(s.at(i));
    }
    ll ans = 0 ;
   
    rep(i, n.size()){
        ans += n.top() * pow(10, i);
        n.pop();
    }
    return ans;
}