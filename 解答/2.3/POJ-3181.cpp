#include<iostream>
using namespace std;
unsigned long long dp[100+16][1000+16][2];

#define LIMIT_ULL 100000000000000000

int main(){
    int N,K;
    cin>>N>>K;
    dp[0][0][1]=1;
    for(int i=1;i<=K;i++){
        for(int k=0;k<=N;k+=i){
            for(int j=N;j>=k;j--){
                dp[i][j][0]+=dp[i-1][j-k][0];
                dp[i][j][1]+=dp[i-1][j-k][1];
                dp[i][j][0]+=dp[i][j][1]/LIMIT_ULL;
                dp[i][j][1]=dp[i][j][1]%LIMIT_ULL;
            }
        }
    }
    if(dp[K][N][0]>0)cout<<dp[K][N][0];
    cout<<dp[K][N][1]<<endl;
    return 0;
}
