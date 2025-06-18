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


int prime[(int)1e7+1];
void prm() {
    for(int i = 2 ; i <= 1e7 ; i++) {
        if(prime[i]) for(int j = i*2 ; j <= 1e7 ; j += i) prime[i+j] = 0;
    }
    return;
}


int main() {
    // set_time(start);
    ofstream file;
    string fname = "in.txt";
    file.open(fname, ios::out);
    file.clear();
    for(auto &p : prime) p = 1;
    prime[0] = prime[1] = 0;

    for(int i = 2 ; i <= 1e7 ; i++) if(prime[i]) file << i << endl;
    file.close();
    // set_time(end);
    // show_time(start, end);
}