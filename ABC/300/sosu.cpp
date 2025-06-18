#include <bits/stdc++.h>
#include <fstream>
using namespace std;



int main() {
    ofstream file;
    file.open("sosu.txt", ios::out);
    file.clear();
    

    set<int> prime; prime.insert(2);
    for(int i = 2 ; i <= 1e6 ; i++) {
        for(auto p = prime.begin() ; p != prime.end() ; p++) {
            if(i % *p == 0) break;
            if(p == --prime.end()) {
                prime.insert(i);
                file << i << ", ";
            }
        }
    }
    file.close();
    cout << prime.size() << endl;
}