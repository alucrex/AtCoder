#include<bits/stdc++.h>
using namespace std;

int main(){
    int a=0,b=0,c=0,d=0;
    cin >>a>>b>>c>>d;
    int min=a;

    if(a<=b){
        min=a;
    }else min=b;
    if(c < min)min=c;
    if(d < min)min=d;
    cout<<min << endl;
    return 0;
}