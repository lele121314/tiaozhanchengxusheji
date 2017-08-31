#include<cstdio>
#include<algorithm>
using namespace std;
long dp[1005][33];
bool a[1005];
int main(){
    freopen("1.txt","r",stdin);
    int t,w;
    scanf("%d%d",&t,&w);
    for(int i=1;i<=t;i++){
        int x;
        scanf("%d",&x);
        if(x==1)a[i]=0;
        else a[i]=1;
    }
    for(int i=1;i<=t;i++ ){
        for(int j=0;j<=w;j++){
            int sta=j%2;
            if(j>=1)
            dp[i][j]=max(dp[i-1][j]+(a[i]==sta),dp[i-1][j-1]+(a[i]!=sta));
            else {
                dp[i][j]=dp[i-1][j]+(a[i]==sta);
            }
            if(i<j)dp[i][j]=0;
            //printf("%d ",dp[i][j]);
        }
        //printf("\n");
    }
    printf("%ld",dp[t][w]);
}
