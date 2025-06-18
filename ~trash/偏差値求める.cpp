#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
	int N=0, target=0; cin >> N >> target;//データの要素数　求めるやつが何番目にいるか
	vector<int> s(N,0);
	int total=0;
	double distributed=0, ave=0, deviation=0;
	double score=0;
	
	/*数値入力、平均*/
	for(int i=0; i<N; i++){
		cin >> s[i];
		total +=s[i];
	}
	ave = total / N;
	
	/*分散*/
	for(int i=0; i<N; i++){
		distributed += (ave - s[i])*(ave - s[i]);
	}
	distributed /= N;
	
	/*標準偏差*/
	deviation = sqrt(distributed);
	
	/*計算*/
	score = ((s[target-1] - ave) / deviation) * 10 +50;
	if(score < 0) score *= -1;
	cout << score << endl;
}