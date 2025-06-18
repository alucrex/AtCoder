#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

bool judge();

int main(){
	bool ans =judge();
	if(ans == false)	cout << "No" << endl;
	else cout << "Yes" << endl;
}

bool judge(){
	int N = 0;
	int M = 0;
	ll T = 0;
	cin >> N >> M >> T;
	const int N_max = N;
	vector<vector<int>> caffe(M, vector<int>( 2, 0));
	vector<ll> cafe(T*2, 0);
	for(int i=0;i<M;i++){
		cin >> caffe.at(i).at(0) >> caffe.at(i).at(1);
		for(int j=caffe.at(i).at(0)*2; j<caffe.at(i).at(1)*2;j++){
			cafe.at(j) = 1;
		}
		//cout << "caffe.at(" << i << ").at(0) = " << caffe.at(i).at(0) << " caffe.at(" << i << ").at(1) = " << caffe.at(i).at(1) << endl;
	}
	
	int count=0;
	bool part = false;
	for(ll i = 0; i < T*2; i++){
		//cout << i/2  << "\t| " <<  N << " : " << cafe.at(i) << endl;
		if( N <= 0 ) return false;
		/*if( cafe.at(i) == 1){
			if(cafe_charge % 2 != 0)N++;
			if(N > N_max) N = N_max;
			cafe_charge++;
			continue;
		}
		if( cafe.at(i) == 0)cafe_charge = 0;*/
		if(count < M ){
			if(caffe.at(count).at(0)*2 == i){
				part = true;
				continue;
			}
			if(caffe.at(count).at(1)*2 == i){
				part = false;
				count++;
			}
			if( i % 2 != 0 && part == true){
				N++;
				if(N > N_max) N = N_max;
				continue;
			}
		}
		if(i % 2 != 0)N--;	
		if( N <= 0) return false;
	}
	return true;
}