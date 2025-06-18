#include <bits/stdc++.h>    //AC
using namespace std;

int main(){
    string a;
    cin >> a;
    for(int i=0; i<a.size(); i++){
        if(a.at(i) == '.'){
            break;
        }
        cout << a.at(i);
    }
    puts("");
}