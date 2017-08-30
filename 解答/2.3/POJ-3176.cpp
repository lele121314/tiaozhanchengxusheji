#include<cstdio>
#include<cstring>
using namespace std;
long long ans=0;
int dp[356],ndp[356];
int a[356];
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int n;
    freopen("1.txt","r",stdin);
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&a[j]);
            ndp[j]=max(dp[j-1],dp[j])+a[j];
        }
        memcpy(dp,ndp,sizeof(int)*(i+1));
    }
    int ans=dp[1];
    for(int i=1;i<=n;i++){
        ans=max(dp[i],ans);
    }
    printf("%d",ans);
}
