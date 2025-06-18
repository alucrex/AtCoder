#include <bits/stdc++.h>//解説見た
using namespace std;
using ll = uint64_t;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int main(){
    int a,b,w;
    cin >> a >> b >> w;
    w *= 1000;
    int ans_min = w, ans_max = 0;   // n*x = w
    for(int n = 1 ; a*n <= w ; n++){//a< x < b
        if( a*n <= w && w<= b*n){             //a< w/n < b
            ans_min = min(ans_min, n);
            ans_max = max(ans_max, n);
        }
    }
    if(ans_max == 0)cout << "UNSATISFIABLE";
    else cout << ans_min << " " << ans_max << endl;
}