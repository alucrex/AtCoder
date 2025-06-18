#include <bits/stdc++.h>	//AC
using namespace std;

int ll(int n){
	if(n<0) return -n;
	if(n>=0) return n;
	cout << "err" << endl;
	return 0;
}

int judge(vector<int>, pair<int,int>);

int main(){
	pair<int,int> a(0,0);	//aにある駒をbに移動
	pair<int,int> b(0,0);
	pair<int,int> c(0,0);	//aを原点としてbの座標を計算
	vector<vector<int>> other(10,vector<int>(2,0));
	int result =0;
	cin >> a.first >> a.second >> b.first >> b.second;
	c.first = b.first - a.first;
	c.second = b.second - a.second;
	
	vector<int> result_temp(10,0);
	other.at( 0)={-2, 2};
	other.at( 1)={-1, 2};
	other.at( 2)={ 0, 2};
	other.at( 3)={ 1, 2};
	other.at( 4)={ 2, 2};
	other.at( 5)={-2,-2};
	other.at( 6)={-1,-2};
	other.at( 7)={ 0,-2};
	other.at( 8)={ 1,-2};
	other.at( 9)={ 2,-2};
	
	if(c.first == 0 && c.second == 0){
		result = 0;
	}else if((ll(c.first) + ll(c.second) <= 3) || c.first == c.second || c.first == -c.second){
		result = 1;
	}else if(c.first % 2 == c.second % 2 || c.first % 2 == -c.second % 2){
		result = 2;
	}else{
		for(int i=0; i<10; i++){
			result_temp.at(i) = judge(other.at(i),c) + 1;
			//cout << "result_temp.at(" << i << ") = " << result_temp.at(i) << endl;
		}
		sort(result_temp.begin(), result_temp.end());
		result = result_temp.at(0);
	}
	cout << result << endl;
	
}

int judge(vector<int> a, pair<int,int> c){//compare
	vector<int> comp(2);	//移動後の対象の座標
	comp.at(0) = c.first - a.at(0);
    comp.at(1) = c.second - a.at(1);
	if((ll(comp.at(0)) + ll(comp.at(1)) <= 3) || comp.at(0) == comp.at(1) || comp.at(0) == -comp.at(1)){
		return 1;
	}else if(comp.at(0) % 2 == comp.at(1) % 2 || comp.at(0) % 2 == -comp.at(1) % 2){
		return 2;
	}else return 2;
}