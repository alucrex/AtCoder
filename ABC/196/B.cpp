#include <bits/stdc++.h>
using namespace std;

int main(){
	double a=0.0;
	uint64_t x=0,y=0;
	cin >> a;
	
	double b=a;
	int count=1;
	while(b >=10){
		b/=10;
		count++;
	}
	if(count >20){
		x = (uint64_t)a;
		y = (uint64_t)(a /(10*20));
		cout << y << x << endl;
	}else{
		cout << (uint64_t)a << endl;
	}
}