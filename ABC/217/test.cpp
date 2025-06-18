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
    int L = rand();
    int Q = rand();
    file << L << " " << Q << "\n";
    set<int> used;
    vector<int> v(L-1);
    for(int i = 1 ; i <= L-1 ; i++) v[i-1] = i;
    rep(i, Q) { //このコード遅すぎて使い物にならない
        printf("i : %d / %d\n", i+1, Q);
        int c = rand() % 2;
        int x = v[rand() % v.size()];
        v.erase(lower_bound(v.begin(), v.end(), x));
        file << c+1 << " " << x << "\n";
    }
    file.close();
}