#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < (n) ; i++)
#define rep1(i,n) for(int i = 1 ; i <= (n) ; i++)
#define rrep(i,n) for(int i = (n) - 1 ; i >= 0 ; i--)
#define rrep1(i,n) for(int i = (n) ; i > 0 ; i--)
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
#define Yn(x) cout << ((x) ? "Yes" : "No") << endl;
#define yn(x) cout << ((x) ? "yes" : "no") << endl;
#define mmax(a,b) a = max(a,b)
#define mmin(a,b) a = min(a,b)
#define debug(x) cout << #x" : " << (x) << endl;
#define output(x) cout << (x) << endl;
#define mod(n,x) (n) % (x)
#define all(a,b) (a).begin(),(b).end()

class alucrex{
    public:
        int intinput(){int a;cin >> a;return a;}
        ll llinput(){ll a;cin >> a;return a;}
        double dbinput(){double a;cin >> a;return a;}
        long double ldbinput(){long double a;cin >> a; return a;}
};

bool judge(deque<ll>& q, int x, int y){
    int minus = 0, plus = 0, sum = 0, size = q.size();
    rep(i,q.size()){
        int a = q.front();
        q.pop_front();
        q.push_back(a);
        (a < 0) ? minus++ : plus++;
        sum += a;
    }
    if(x == minus && y == plus && sum == 0 && size == x + y)return true;
    return false;
}

int main(){
    alucrex al;
    int a = al.intinput(), b = al.intinput();
    int m = min(a,b);
    int ma = max(a,b);
    deque<ll> ans;
    rep1(i,ma){
        ans.push_front(-1*i);
        ans.push_back(i);
    }

    // if(abs(a-b)>m){
        int nokori = 0;
        if(a < b){
            rep(i,abs(a-b)+1){
                nokori += ans.front();
                ans.pop_front();
            }
            ans.push_front(nokori);
        }else{
            rep(i,abs(a-b)+1){
                nokori += ans.back();
                ans.pop_back();
            }
            ans.push_back(nokori);
        }
    // }else if(a < b){
    //     for(int i = 0 ; i < b - a ; i++){
	//         int x1 = ans.at(i);
    //         ans.pop_front();
    //         int x2 = ans.at(i);
    //         ans.pop_front();
    //         ans.push_front(x1 +x2);
    //     }
    // }else if(a > b){
    //     for(int i = ans.size()-1, cnt = 0; cnt < a - b ; i--, cnt++){
	//         int x1 = ans.at(i);
    //         ans.pop_back();
    //         int x2 = ans.at(i-1);
    //         ans.pop_back();
    //         ans.push_back(x1 +x2);
    //     }
    // }
    // debug(judge(ans,a,b));
    while(ans.empty() != true){
        cout << -1*ans.front() << " ";
        ans.pop_front();
    }
    puts("");
}