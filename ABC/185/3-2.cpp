#include <bits/stdc++.h>
using namespace std;

int main(){
	int n=0, r=0;
	int >> n >> r;
	cout << C(n, r) << endl;
}

int C(int n, int r){
	double x=0;
	for(int i=r; i>0; i--){
		x *=  (double)n / (double)i;
	}
	return (int)x;
}