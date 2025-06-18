#include <bits/stdc++.h>
using namespace std;
using ll = uint64_t;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

bool judge(int, int);
int soin(int);

int main(){
    int a,b,w;
    cin >> a >> b >> w;
    w *= 1000;
    int ans_min = w, ans_max = 0;   // n*x = w
    for(int n = 1 ; a*n <= w ; n++){//a< x < b
        if(/*judge(w,n) &&*/ a*n <= w && w<= b*n){             //a< w/n < b
            ans_min = min(ans_min, n);//整数型での割り算は正確じゃないから移項する！！！！！！！！！！
            ans_max = max(ans_max, n);//judge()なくせばよかっただけ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
        }
    }
    if(ans_min == ans_max){//みかんはすべて同じ重さでなくてもいいらししいけど、無理だよ。。。。
        // ans_min =
    }
    if(ans_max == 0)cout << "UNSATISFIABLE";
    else cout << ans_min << " " << ans_max << endl;
}


bool judge(int a,int b){//a/bが割り切れるか
    int qa = soin(a);
    int qb = soin(b);
    if(qa % qb == 0)return true;
    
    return false;
}

int soin(int num){//2,5で割ったのこり
    int r;//returnのr
    while (num % 2 == 0){
        num /= 2;
    }
    while( num % 5 == 0){
        num /= 5;
    }
    r = num;
    return r;
}