#include<iostream>
using namespace std;

const int MOD=1e6;
int family[1000+16];
int dp[10000+16][10000+16];


int main(){
    int T,A,S,B;
    cin>>T>>A>>S>>B;
    for(int i=0;i<A;i++){
        int index;
        cin>>index;
        family[index]++;
    }
    dp[0][0]=1;
    int total=family[0];
    for(int i=1;i<=T;i++){
        total+=family[i];
        for(int k=0;k<=family[i];k++){
            for(int j=total;j>=k;j--){
                dp[i][j]=(dp[i][j]+dp[i-1][j-k])%MOD;
            }
        }

    }
    int result=0;
    for(int i=S;i<=B;i++){
        result=(result+dp[T][i])%MOD;
    }
    cout<<result<<endl;
    return 0;
}
