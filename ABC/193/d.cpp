#include <bits/stdc++.h>//全事象がわからないよ…（同じ数のカードを分けるか分けないか
using namespace std;//解説見てAC.カードはすべて分けて数える、間違えた理由は「同じカードを選んだとき」の条件をif(num[i] == num[j])としてたため(i = j だからそら全部おなじになるよな)
using ll = int64_t;
#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define rrep(i, n) for(int i = n ; i > 0 ; i++)

struct s{
    int a = 0;
    int t = 0;
};

int main(){
    int K;
    string T, A;
    cin >> K >> T >> A;
    vector<int> num(9,K);
    vector<int> A_card_count(9, 0);
    vector<int> T_card_count(9, 0);
    s score;
    ll count = 0;
    ll all_events = 0;
    rep(i, 4){
        num.at(T.at(i) - '0' -1) --;//残りのカードの枚数
        num.at(A.at(i) - '0' -1) --;
        T_card_count.at(T.at(i) - '0' -1)++;
        A_card_count.at(A.at(i) - '0' -1)++;
    }
    
    auto scoreCul = [](vector<int> card_count){
        int result = 0;
        for(int i = 1 ; i <= 9 ; i++){
            // std::cout << i + 1 << " : " << i << " * " << 10 << "^" << card_count[i-1] << endl;
            result += i * pow(10, card_count[i-1]);
        }
        return result;
    };
    score.t = scoreCul(T_card_count);
    score.a = scoreCul(A_card_count);

    all_events = (ll)(9*K - 8) * (9*K - 9);

    rep(i, 9){//AOKI
        if(num[i] == 0)continue;
        A_card_count[i] ++;
        num[i]--;
        rep(j, 9){//TAKAHASHI
            if(num[j] == 0)continue;
            num[j]--;
            T_card_count[j]++;

            if(scoreCul(T_card_count) > scoreCul(A_card_count)){
                // cout << "takahashi : " << j + 1 << " aoki : " << i + 1 << endl;
                if(i == j){
                    count += (ll)(num[i]+2) * (num[i]+1);
                    // cout << (num[i]+2) << " * " << (num[i]+1) << endl;
                }else{
                    count += (ll)(num[i] + 1) * (num[j] + 1);
                    // cout << num[i] + 1 << " * " << num[j] + 1 << endl;
                }
            }

            T_card_count[j]--;
            num[j]++;
        }
        A_card_count[i] --;
        num[i]++;
    }

    std::cout << fixed << setprecision(7);
    //std::cout << count << " / " << all_events << endl;
    std::cout << (double)count / (double)all_events << endl;
}