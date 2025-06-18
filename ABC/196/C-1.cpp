#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin >> N;
	int c=0;		//条件を満たす整数の数
	for(int i=0; i<N; i++){
		int count=0;
		int n = i+1;
		while(n>0){
			n/= 10;
			count++;
		}
		if(count % 2 == 0){
			int a=0, b=0;
			int kari=pow(10,count/2);
			
			a = (i+1) / pow(10,count/2);
			b = (i+1) % kari;
			if(a == b) c++;
		}
	}
	cout << c << endl;
}