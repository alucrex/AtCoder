#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rep1(i,n) for(int i = 1 ; i < n ; i++)
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i++)
#define INF 1001001001
using ll = int64_t;
using P = pair<int, int>;

struct type{
    int a = 0;
    int b = 0;
    int c = 0;
};

int main(){
    int n;
    cin >> n;
    vector<type> fortune(n);
    vector<type> s(n);
    rep(i,n){
        cin >> fortune[i].a >> fortune[i].b >> fortune[i].c;
    }
    s[0].a = fortune[0].a;
    s[0].b = fortune[0].b;
    s[0].c = fortune[0].c;
    rep1(i, n){
        s[i].a += max(s[i-1].b, s[i-1].c) + fortune[i].a;
        s[i].b += max(s[i-1].a, s[i-1].c) + fortune[i].b;
        s[i].c += max(s[i-1].a, s[i-1].b) + fortune[i].c;
    }
    cout << max(s[n-1].a, max(s[n-1].b, s[n-1].c)) << endl;

}