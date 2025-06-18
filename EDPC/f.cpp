#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rep1(i,n) for(int i = 1 ; i < n ; i++)
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define rrep1(i, n) for(int i = n ; i > 0 ; i--)
#define INF 1001001001
using ll = int64_t;
using P = pair<int, int>;


int main(){
    string s, t;
    cin >> s >> t;
    int slen = s.size()+1, tlen = t.size()+1;
    vector<vector<int>> dp(slen, vector<int>(tlen, 0));
    string ans;

    rep1(i,slen)rep1(j,tlen){
        if(s[i-1] == t[j-1])dp[i][j] = dp[i-1][j-1] + 1;
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
    // cout << dp[s.size()][t.size()] << endl;

    //desclibe dp table
    cout << "    / ";
    rep(i,t.size())cout << t[i] << " ";
    cout << endl;
    rep(i,slen){
        if(i == 0)cout << "    ";
        else cout << s[i-1] << " | ";
        rep(j,tlen){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    int i = s.size(), j = t.size();
    for(int k = 0 ; k < dp[s.size()][t.size()] ;){
        if(dp[i][j] == dp[i-1][j])i--;
        else if(dp[i][j] == dp[i][j-1])j--;
        else if(dp[i][j] == dp[i-1][j-1] +1){
            ans += s[i-1];
            i--; j--; k++;
        }
        
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}