#include <bits/stdc++.h>
using namespace std;

int main(){
	int L=0;
	uint64_t ans =1;
	cin >> L;
	for(int i=0; i< 11; i++){
		ans *= (L -1 -i);
	}
	cout << ans / (11*10*9*8*7*6*5*4*3*2) << endl;
	
}