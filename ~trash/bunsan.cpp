#include <bits/stdc++.h>
#include <math.h>
using namespace std;
//そのうち構造体で作りたい
int main(){
  cout << "a";
	int N=0, M=0;//データの要素数、何個の列か
	vector<vector<double>> data(M,vector<double> (N,0));
	vector<vector<double>> h(M,vector<double> (N,0));		//偏差
	vector<double> total(M,0);							//合計
	vector<double> ave(M,0);							//平均
	vector<double> ss(M,0);							//分散
	vector<double> s(M,0);								//標準偏差
	vector<vector<double>> Q(M,vector<double>(3,0));	//四分位数
	
	for(int i=0; i<M ;i++){
		for(int j=0; j<N; j++){
			cin >> data.at(i).at(j);
			total.at(i) +=data.at(i).at(j);		//合計
		}
		ave.at(i) = total.at(i) / N;			//平均
		if(N % 4 ==0){		//四分位数
			Q.at(i).at(0) = data.at(i).at(N/4-1);
			Q.at(i).at(1) = data.at(i).at(N/2-1);
			Q.at(i).at(2) = data.at(i).at(N/4*3-1);
		}else if(N % 2 ==0){
			Q.at(i).at(0) = (data.at(i).at(N/4-1) + data.at(i).at(N/4)) /2;
			Q.at(i).at(1) = data.at(i).at(N/2-1);
			Q.at(i).at(2) = (data.at(i).at(N/4*3-1) + data.at(i).at(N/4*3)) /2;
		}else{
			Q.at(i).at(0) = (data.at(i).at(N/4-1) + data.at(i).at(N/4)) /2;
			Q.at(i).at(1) = (data.at(i).at(N/2-1) + data.at(i).at(N/2)) /2;
			Q.at(i).at(2) = (data.at(i).at(N/4*3-1) + data.at(i).at(N/4*3)) /2;
		}
	}
	
	for(int i=0; i<M ;i++){
		for(int j=0; j<N; j++){
			h.at(i).at(j) = data.at(i).at(j) - ave.at(i);
			ss.at(i) += h.at(i).at(j);
		}
		ss.at(i) /= N;
		s.at(i) = sqrt(ss.at(i));
	}
	
	for(int i=0; i<M; i++){
		cout << "平均：" << ave.at(i) <<endl;
		cout << "第一四分位数：" <<Q.at(i).at(0) << "　第二四分位数：" << Q.at(i).at(1) << "　第三四分位数："  <<Q.at(i).at(2) << endl;
		cout << "分散：" <<ss.at(i) << "標準偏差：" << s.at(i)<<endl;
	}
}