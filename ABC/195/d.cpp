#include <bits/stdc++.h>//AC!!
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
int solve(vector<int>, vector<int>, vector<pair<int, int>>);

int main(){
    int N , M , Q;
    cin >> N >> M >> Q;
    vector<pair<int, int>> b(N);
    vector<int> box_cap(M, 0);
    vector<vector<int>> q(Q , vector<int>(2 , 0));
    rep(i, N){//荷物の重さ、価値 1<= N <= 50
        cin >> b[i].second >> b[i].first;
    }
    //価値のソート
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    rep(i, M){//箱の大きさ 1<= M <=50
        cin >> box_cap.at(i);
    }
    rep(i, Q){//クエリの取得 1<= Q <= 50
        cin >> q[i][0] >> q[i][1];
    }
    rep(i, Q){//結果の出力
        cout << solve(q[i], box_cap, b) << endl;
    }
}

int solve(vector<int> q, vector<int> boxcap, vector<pair<int, int>> bag){//bag.first = 価値 bag.second = 重さ
    int ans = 0;
    //使えない箱を消す
    for(int i = q[0] - 1 ; i < q[1] ; i++){ //<50
        boxcap[i] = 0;
    }
    //箱のソート
    sort(boxcap.begin(), boxcap.end());//O(logM)

    //価値の大きいものからなるべくギリギリの箱に入れる
     rep(i, bag.size()){//荷物の価値の大きいやつからそれぞれを
        rep(j, boxcap.size()){//小さい箱から順に見る
            if(bag[i].second <= boxcap[j]){
                ans += bag[i].first;
                boxcap[j] = 0;
                break;
            }
        }
    }
    return ans;
}