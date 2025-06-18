#include <iostream>
using namespace std;

int main(){
	int x[4];
	int m=4;
	
	for (int i=0;i<=4;i++){
		x[i]=0;
		cin >> x[i];
	}

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
	
	cout << x[0] << endl;
	return 0;
}