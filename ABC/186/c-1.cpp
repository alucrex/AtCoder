#include <bits/stdc++.h>//AC
using namespace std;
using ll = uint64_t;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

/*struct num{
	int n = 0;//number
	int x = 0;//ketasuu
	void operator=(const num &other){
		n = other.n;
		x = other.x;
	}
};*/

int from10_to_8(int);
bool judge(int);

int keta(int n){
	int count = 0;
	while( n != 0){
		n /= 10;
		count++;
	}
	return count;
}

int main(){
	int N = 0;
	cin >> N;

	int ans = 0;
	for(int i = 1; i <= N ; i++){
		int ver_8 = from10_to_8(i);
		int ver_10 = i;
		if(judge(ver_10) == true && judge(ver_8) == true)ans++;
	}
	cout << ans << endl;
}

int from10_to_8(int ver_10){
	if(ver_10 == 0)return 0;
	int x = 0;
	int vv = ver_10;
	for( ; vv / 8 > 0 ; x++){
		vv /= 8;
	}//8^x <= ver_10
	/*while(vv != 0){
		vv /= 8;
		e++;
	}
	e /= 8;*/
	int ver_8 = 0;
	for(int i = 0 ; i < x + 1 ; i++){
		ver_8 += (ver_10 % 8) * pow(10, i);
		ver_10 /= 8;
	}
	return ver_8;
}

bool judge(int num){
	string ns = to_string(num);
	rep(i,ns.size()){
		if(ns.at(i) == '7')return false;
	}
	return true;
}