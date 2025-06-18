#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define NUMBER 31
int from10(int);
void substitutionToBit(bitset<NUMBER>&, int);

int main(){
    int n;
    cin >> n;
    vector<bitset<NUMBER>> a(n,0);
    rep(i, n){
        int n;
        cin >>n;
        string ver_2 = to_string(from10(n));
        cout << ver_2 << endl;
        for(int j = ver_2.size() - 1 ; j >= 0 ; j--){
            if(ver_2.at(j) - '0'){
            a.at(i).set(ver_2.size() - j);
            }
        }
    }

    vector<bitset<NUMBER>> total(n - 1);
    for(int i = 0, j = 1; j < n ; i++ , j++){//にこ撮ってきて、それのor探す
        substitutionToBit(& total.at(i), (a.at(i) | a.at(j)));
        
    }

int from10(int ver_10){//10進数からn進数
    int n = 2;
	if(ver_10 == 0)return 0;
    if(n <= 0){
        std::cout << "err" << std::endl;
        return -1;
    } 
	int x = 0;
	int vv = ver_10;
	for( ; vv / n > 0 ; x++){//n進数に変換したとき何桁か
		vv /= n;//O(logn(N))
	}
	int ver_n = 0;
	for(int i = 0 ; i < x + 1 ; i++){
		ver_n += (ver_10 % n) * pow(10, i);
		ver_10 /= n;
	}
	return ver_n;
}
#define NUMBER 31
void substitutionToBit(bitset<NUMBER>& bit, int num){

    string ver_2 = to_string(from10(num));
    for(int j = ver_2.size() - 1 ; j >= 0 ; j--){
        if(ver_2.at(j) - '0'){
            bit.set(ver_2.size() - j);
        }
    }
}