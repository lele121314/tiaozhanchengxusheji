#include<cstdio>
#include<algorithm>

using namespace std;
struct E{
    int a,b,e;
    bool operator <(const E &y) const{
        if(a!=y.a)return a<y.a;
        else return b<y.b;
    }
}edge[1001];
int dp[1001];
int main(){
    int n,m,r;
    scanf("%d%d%d",&n,&m,&r);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].e);
        edge[i].b+=r;
    }
    sort(edge,edge+m);
    for(int i=0;i<m;i++){
        dp[i]=edge[i].e;
        for(int j=0;j<i;j++){
            if(edge[j].b<=edge[i].a){
                dp[i]=max(dp[i],dp[j]+edge[i].e);
            }
        }
    }

    printf("%d",*max_element(dp,dp+m));
}
