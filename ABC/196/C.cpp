#include <bits/stdc++.h>
using namespace std;
int sum(int);
int keta(int);

int main(){
	int N;
	cin >> N;
	int count= keta(N);
	int c=0;//答え
	
	c+= sum((count-1)/2);	//n-1ケタまでのカウント
	
	if(count%2 == 0){
		int a=0, b=0;
		int kari=pow(10,count/2);
		a = N / pow(10,count/2);
		b = N % kari;
		
		int m = min(a,b);
		int count_m = keta(m);
		int kk = pow(10,count_m-1);
		c+= m - kk;
	}
	
	cout << c<<endl;
}

int sum (int n){//桁数答えたら答えてくれる
	int r=0;
	for(int i=0; i<n; i++){
		r += 9*pow(10,i);
	}
	return r;
}//もう無理だ…

int keta (int n){
	int count=0;
	while(n>=0){
		n/=10;
		count++;
	}
	return count;
}