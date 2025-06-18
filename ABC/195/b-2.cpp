#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,w;
    cin >> a >> b >> w;
    w *= 1000;
    int m = w/b,M = w/a;
    if(w % b != 0)m++;
    if(m > M)cout << "UNSATISFIABLE" <<endl;//not >= 
    else cout << m << " " << M << endl;
}