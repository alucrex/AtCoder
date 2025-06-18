#include <iostream>
using namespace std;

int main(){
    int x[4];

    for(int i=0;i<=4;i++){
        x[i]=0;
        cin >> x[i];
        cout << i << " = " << endl;
    }

    int q;
    while(q<4){
        for(int i=0;i<4;i++){
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
        q++;
    }
    cout << x[0];
}