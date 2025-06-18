#include <bits/stdc++.h>
using namespace std;
using ll = uint64_t;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

ll keta(ll num){
    std::string s = std::to_string(num);
    return s.size();
}

void r(ll N){
    // ll N;
    //cin >> N;
    int Nk = keta(N);
    ll ans = 0;
    const ll NN = N;
    int p = (Nk-1)/3;//nケタの数のカンマの数
    //cout << "p = " << p << endl;
    for(int i = p - 1 ; i > 0 ; i--){// 1,000,000のとき999,999から1,000を計算してもらう
        //cout << i << " * " << pow(10, (i + 1)* 3) << " - " << pow(10, i * 3) << " * " << endl;//int(N/pow(10,(i+1)*3)) << endl;
        ans += i * (pow(10, (i + 1)* 3) - pow(10, i* 3));// * int(N/pow(10,(i+1)*3));
        N -= (N / pow(10, (i + 1) * 3)) * pow(10, (i + 1) * 3);//切り捨て
        if(N == 0) N = pow(10,i*3);
    }
    if(p == 1 || (NN != pow(10, p*3) && NN >= 1000)){
        //cout << NN << " - " << (ll)pow(10, p*3) << endl;
        ans += (NN - (ll)pow(10, p*3)+1)*p;
    }
    cout << ans << endl;
}
int main(){
    for(int i = 1; i <= 15 ; i++){
        r(pow(10,i));
    }
}