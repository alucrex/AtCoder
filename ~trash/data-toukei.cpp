#include <bits/stdc++.h>
using namespace std;

int main(){
  int N=0;						//データの要素数
  cin>>N;
  double ave=0, aave=0,ss=0,s=0;
  vector<int> deta(N,0);
  
  /*計算*/
  for(int i=0; i<N; i++){
    cin >> deta.at(i);
    ave += deta.at(i);
    aave+= deta.at(i)*deta.at(i);
  }ave/=N;aave/=N;
  sort(deta.begin(),deta.end());
  ss = aave-ave*ave;
  s = sqrt(ss);

  /*書き出し*/
  for(int i; i< deta.size(); i++)
    cout << deta.at(i) <<"  "<< i+1<<endl;
  cout << "ave:" <<ave;
  cout << endl;
  cout << "aave:" << aave<<endl;
  cout << "ss:" << ss<<endl;
  cout << "s:" << s;
	
}