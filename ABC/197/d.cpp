#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

struct coodination{
    double x = 0;
    double y = 0;
};

int main(){
    int n;
    coodination cood0;
    coodination coodm;
    coodination m;
    double md = 0 ;
    double d = 0;
    cin >> cood0.x >> cood0.y >> coodm.x >> coodm.y;
    m.x = (cood0.x + coodm.x);
    m.y = (cood0.y + coodm.y);
    md = sqrtl( (coodm.x - cood0.x, 2) * (coodm.x - cood0.x, 2) + (coodm.y - cood0.y) * (coodm.y - cood0.y) ) /2;
    d = md * cos( 180*(n - 2) / 2*n) *2;
}