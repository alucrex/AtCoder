#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
using ll = long long;

#include <fstream>

int main() {
    srand(time(NULL));
    ofstream file;
    file.open("in.txt", ios::out);
    file.clear();
    int mod = 500;
    int M = 100;
    int n = (rand() % mod) + 1;
    file << n << endl;
    rep(i, n) {
        int a = rand() % M + 1;
        int b = rand() % M + 1;
        file << a << " " << b << endl;
    }
    file.close();
}