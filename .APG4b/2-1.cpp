#include <bits/stdc++.h>
using namespace std;

int ruijou(int);
int C(int,int);
int er();

int main() {
  int N, S;
  cin >> N >> S;
  vector<int> A(N), P(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);//りんご
  }
  for (int i = 0; i < N; i++) {
    cin >> P.at(i);//パイナップル
  }
  vector<int> all(N*2,0);
  for(int i=0;i<N ;i++){
    all.at(i) = A.at(i);
  }
  for(int i=0; i<N ;i++){
    all.at(N+i) = P.at(i);
  }
  int count=0;
  // リンゴ・パイナップルをそれぞれ1つずつ購入するとき合計S円になるような買い方が何通りあるか
  // ここにプログラムを追記
	for(int i=0; i<N*2; i++){//1個選ぶとき2個選ぶとき…
		cout << i+1 << "個選ぶとき" << endl;
		int pattern=C(N*2,i+1);//何通りの選び方があるか
		
		vector<int> q(i+1,0);//比べる数の分だけ変数を作るa,b,cみたいに指定するため＋オーバーフロー防止
		for(int k=0;k<i+1;k++){
			q.at(k) = k;
		}
		
		for(int j=0; j<pattern; j++){
			
			int compare=0;
			for(int k=0; k<i+1; k++){
				cout << all.at(q.at(k)) << "　：　";
				compare += all.at(q.at(k));
			}cout << endl;
			if(compare == S) count++;
				
				/*考えられる組み合わせ次のやつ*/
			for(int k=0; k<i+1; k++){
			
				/*最後の一桁のときの処理*/
				if(q.at(i-k) == i){ 								//下一桁が最後に到達していた場合 下一桁を前に戻す
					cout << "q.at(" << i << "-" << k << ")" << endl;
					if(i==0)continue;							//一桁しかない場合はスルー
					if(q.at(i-k) == q.at(i-k-1) + 1)continue;	//前の桁がすぐそこにいるときもスルー
					
				/*中処理*/
				}else if(q.at(i-k) + 1 == q.at(i-k+1))continue; //中処理：桁を一つ右にずらしたとき次の桁と重なる場合
				else{ 											//中処理：桁を一つ右にずらせるとき(それより右の桁を前に戻すwhile使って）
					q.at(i-k)++;
					for(int l=1; l<k+1;l++){					//右にあるやつを戻す
						q.at(i-k+l) = q.at(i-k) + l;
					}
					break;
				}
			}
		}
	}
	cout << count << endl;
}

int ruijou(int num){
	int ans=1;
	if(num < 0){
		return -1;
	}else{
		for(int i=0; i<num ;i++){
			ans *= i+1;
			//ans *=num-i ←num==0のときエラー
		}
	}
	return ans;
}

int C(int r,int n){//ok
	int sum_r=1, sum_n=1;
	if(r < -1 || n < -1){
		return er();
	}else if( r < n ){
		return er();
	}if(n == 0 || r == n){
		return 1;
	}else{
		for(int i; i<n; i++){
			sum_r *= r-i;
			sum_n *= n-i;
		}
	}
	return sum_r / sum_n;
}

/*vector<int> Cv(int r,int n){
	max = r-n;
	vector<int> ans(max,0);
	for(int i=0; i < max; i++){
		ans.at(i) = max - i
}*/

int er(){
	cout << "error" << endl;
	return -1;
}