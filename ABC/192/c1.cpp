#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rep1(i,n) for(int i = 1 ; i < n ; i++)
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define rrep1(i,n) for(int i = n ; i > 0 ; i--)
#define INF 1001001001
#define MOD 1000000007
using ll = int64_t;
using P = pair<int, int>;
using PL = pair<ll,ll>;
using PD = pair<double,double>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define v(n) vector<n>
#define vv(n) vector<vector<n>>
#define vvv(n) vector<vector<vector<n>>>
#define line cout << "================================" << endl;

int main(){
	string n;
	int k;
	cin >> n >> k;
	auto f = [](int num){
		string n = to_string(num);
		ll g1 = 0, g2 = 0;
		sort(n.begin(),n.end());//g2
		g2 = stoi(n);
		reverse(n.begin(),n.end());
		g1 = stoi(n);
		return g1 - g2;
	};
	ll ans = stoi(n);
	rep(i,k){
		ans = f(ans);
	}
	cout << ans << endl;
}