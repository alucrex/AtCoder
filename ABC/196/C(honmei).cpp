#include <bits/stdc++.h>//AC
using namespace std;

int main(){
	long N;
	cin >> N;
	int ans=0;
	for(ans; ans < N; ans++){
		if( !(stoll(to_string(ans) + to_string(ans)) <= N) ) break;
	}
	cout << ans-1 << endl;
}