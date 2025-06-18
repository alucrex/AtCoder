#include<bits/stdc++.h>
using namespace std;

int main(){
    int N=0, M=0, t=0;
    cin >> N >> M  >> t; //t+0.5 < totalT
    int time[M][2];
    double totalB[M];//カフェで増えたバッテリー
    int outT[M+1]; //それぞれ外出した時間
    const int f_N = N;

    for (int i=0; i<M; i++){
        for(int j=0; j<2 ;j++){
            time[i][j]=0;
            cin >> time[i][j];//カフェに訪れた時間
        }
            totalB[i]=0;
            totalB[i] = (time[i][1] - time[i][0]+1);//増えるバッテリー
            //outT +=(time[i][1] - time[i][0]);   //外出した時間
            cout << (time[i][1] - time[i][0]+1)*10<< "/"<<15<<"  =  " <<((time[i][1] - time[i][0]+1)*10) /15 <<endl;;
    }
    for (int i=0; i<M+1; i++){//それぞれの外出した時間
        outT[i]=0;

        if(i==0){
            outT[i] = time[i][0];
        }else if(i==M){
            outT[i] = t - time[i-1][1]+1;
        }else {
            outT[i] = time[i][0] - time[i - 1][1]+1;
        } //OK
    }//ここまで数値準備
/*
    for (int i=0; i<M; i++){
        cout << i <<"回目の外出は";
        for(int j=0; j<2 ;j++){
            cout  <<time[i][j] << " , " ;
        }
        cout << endl;
    }*///ok

    //結果　
    /*一回も切れない→*/
   for (int i=0; i<M*2 + 1; i++){     //外出 カフェ　外出　カフェ　外出　家
    cout <<"i= " <<i <<endl;
        if(i%2 ==0){//外出中
            cout << i/2 <<"回目の外出でのバッテリーは"<< N<< "-" << outT[i/2] << " de " ;
            N  -= outT[i/2 ];    //バッテリーがマイナス
            cout<< N<<endl;
            if(N <= 0){
                cout << i/2+1<<"回目の外出"<<endl;
                cout << "No" << endl;
                break;
            }
        }
        if(i%2 == 1){//カフェ中
            cout <<i/2<< "回目でのカフェで"<<totalB[i/2]<<endl;
            N += totalB[i/2];
            if(N>f_N){
                N = f_N;
            }
        }

        if(i == M*2){
            cout << "Yes" << endl;
        }
   }//バッテリープラス

}