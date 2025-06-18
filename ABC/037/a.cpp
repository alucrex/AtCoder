#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0 ; i < n ; i++)

int main() {
    int a, b, c; cin >> a >> b >> c;
    cout << c/min(a, b) << endl;
}