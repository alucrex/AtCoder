#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
using ll = long long;
#include<fstream>

int main() {
    ofstream file;
    file.open("sq.txt", ios::out);

    ll n = 10000000;
    for(ll i = 1 ; i <= n ; i++) {
        // if(i%100000 == 0) cout << i/100000 << "00000" << endl;
        file << i*i << "\n";
    }
    file.close();
}