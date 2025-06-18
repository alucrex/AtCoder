#include<bits/stdc++.h>
using namespace std;
#define Describe for(int i=0; i<=m; i++){cout << x[i] << " , ";}
#define br cout << endl

int main(){
	int n=0,m=0;
	cin >> n >> m;
	int x[--m];
	
	for(int i=0; i<=m; i++){
		x[i]=0;
		cin >> x[i];
	}
	
	//before sort is OK;
	
	//sort stat
	int q=0;
	while(q < m-1){
		if(m==0)break;
		q++;
		
		for(int i=0; i<=m; i++){
			if(i!=0){
				if( x[i-1] <= x[i] ){
					int instead=0;
					
					instead = x[i];
					x[i] = x[i-1];
					x[i-1] = instead;
					
					q=0;
				}
			}
		}
	}
	//sort goal
	
cout << endl;}