#include <bits/stdc++.h>//AC
using namespace std;
using ll = uint64_t;

int main(){
	int L=0;
	cin >> L;
	vector<int> vec = {1,2,3,4,5,6,7,8,9,10,11};
	vector<int> l(11, 0);
	ll ans=1;
	for(int i=1; i<=11; i++){
		l.at(i-1) = L - i;
	}
	/*割り算で値が変わらないようにする*/
	for(int i=10; i>=0; i--){//vec.at
		for(int j=0; j<11; j++){//l.at
			//cout << "l.at(" << j << ") = " << l.at(j) << " , vec.at(" << i << ") = " << vec.at(i) << endl;
			if(vec.at(i) == 1) break;
			if(l.at(j) % vec.at(i) == 0){
				l.at(j) /= vec.at(i) ;
				vec.at(i) = 1;
				break;
			}
		}
	}
	for(auto x : l){
		//cout << x << " * ";
		ans *= x;
	}//cout << endl;
	for(auto x : vec){
		ans /= x;
	}
	cout << ans << endl;
}