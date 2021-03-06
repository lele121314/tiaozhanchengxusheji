#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX_V 1000+6
int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];
int V;
int prim(){
    for(int i=0;i<V;i++){
        mincost[i]=INF;
        used[i]=false;
    }
    mincost[0]=0;
    int res=0;

    while(true){
        int v=-1;
        for(int u=0;u<V;u++){
            if(!used[u]&&(v==-1||mincost[u]<mincost[v]))v=u;
        }

        if(v==-1)break;
        used[v]=true;
        res+=mincost[v];
        //cout<<mincost[v]<<endl;
        for(int u=0;u<V;u++){
            mincost[u]=min(mincost[u],cost[v][u]);
        }
    }
    return res;
}
void dfs(int x){
    if(used[x])return ;
    used[x]=true;
    for(int i=0;i<V;i++){
        if(cost[i][x]<0)dfs(i);
    }
}
int main(){
    freopen("1.txt","r",stdin);
    int M;
    while(~scanf("%d%d",&V,&M)){
//        for(int i=0;i<V;i++){
//            for(int j=0;j<V;j++)
//                cost[i][j]=INF;
//        }
        memset(used,false,sizeof(used));

        while(M--){
            int a,b,t;
            scanf("%d%d%d",&a,&b,&t);
            a--;b--;
            cost[b][a]=cost[a][b]=min(-t,cost[a][b]);
        }
        dfs(0);
        for(int i=0;i<V;i++){
            if(!used[i]){
                printf("-1");
                return 0;
            }
        }
        printf("%d",-prim());
    }
    return 0;
}
