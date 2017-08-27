#include<cstdio>
#include<limits>
#include<algorithm>
using namespace std;
int maxn=-1;
int r,c;
bool adj[11][10001];
int ans;
void dfs(int x){
    //printf("%d\n",x);
    if(x==r+1){
        int newans=0;
        for(int i=0;i<c;i++){
            int nu=0;
            for(int j=0;j<r;j++){
                if(adj[j][i])nu++;
            }
            int nuu=max(nu,r-nu);
            newans+=nuu;
        }
        ans=max(ans,newans);
        return;
    }
    dfs(x+1);
    for(int i=0;i<c;i++){
        adj[x][i]=!adj[x][i];
    }
    dfs(x+1);
}
int main(){
    freopen("1.txt","r",stdin);
    while(scanf("%d%d",&r,&c)!=EOF){
           // printf("ggg\n");
        if(r==0&&c==0)break;
        ans=-1;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int x;
                scanf("%d",&x);
                if(x)adj[i][j]=true;
                else adj[i][j]=false;
            }
        }
        dfs(0);
        printf("%d\n",ans);
    }
    return 0;
}
