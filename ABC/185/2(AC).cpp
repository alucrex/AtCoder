#include <bits/stdc++.h>
using namespace std;
using ll = uint64_t;
bool judge();

int main(){
	cout << (judge() ? "Yes" : "No") << endl;
}


bool judge(){
	int N=0, M=0, T=0;
	cin >> N >> M >> T;
	const int N_max = N;
	vector<int> enter_cafe(M+1,0);
	vector<int> leave_cafe(M+1,0);
	for(int i=1; i<M+1; i++){
		cin >> enter_cafe.at(i) >> leave_cafe.at(i);
	}
	
	for(int i=0; i< M ;i++){
		//walk
		//cout << "walk : "  << N << " - ( " << enter_cafe.at(i+1) << " - " << leave_cafe.at(i) << " ) = ";
		N -= enter_cafe.at(i+1) - leave_cafe.at(i);
		//cout << N << endl;
		if(N <= 0)return false;
		//cafe
		//cout << "cafe : " << N << " + ( " << leave_cafe.at(i+1) << " - " << enter_cafe.at(i+1) << ") = ";
		N += leave_cafe.at(i+1) - enter_cafe.at(i+1);
		//cout << N << endl;
		if( N > N_max ) N = N_max;
	}
	N -= T - leave_cafe.at(M);
	if( N <= 0 )return false;
	return true;
}