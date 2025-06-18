#include <bits/stdc++.h>
#include <chrono>
// using namespace chrono;
using namespace std;
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
using ll = long long;
// #define set_time(x) steady_clock::time_point (x) = steady_clock::now()
// #define p_time(x) duration_cast<milliseconds>(x).count()
// #define show_time(s, e) cout << "実行時間" << duration_cast<milliseconds>(e-s).count() << "ms\n"

#include <fstream>

int main() {
    // set_time(start);
    srand(time(NULL));
    ofstream file;
    string fname = "in.txt";
    file.open(fname, ios::out);
    file.clear();
    int n = 1e5;
    int x = rand() % n;
    file << x << " " << n << endl;
    for(int i = 0 ; i < x ; i++) {
        file << rand() % n << "\n";
    }
    file.close();
    // set_time(end);
    // show_time(start, end);
}