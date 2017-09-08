#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX_V 10000+10
double cost[MAX_V][MAX_V];
double mincost[MAX_V];
bool used[MAX_V];
int V;
pair<int,int> p[MAX_V];
double prim(){
    for(int i=0;i<V;i++){
        mincost[i]=INF;
        used[i]=false;
    }
    mincost[0]=0;
    double res=0;

    while(true){
        int v=-1;
        for(int u=0;u<V;u++){
            if(!used[u]&&(v==-1||mincost[u]<mincost[v]))v=u;
        }

        if(v==-1)break;
        used[v]=true;
        res+=mincost[v];
        //cout<<v<<endl;
        for(int u=0;u<V;u++){
            mincost[u]=min(mincost[u],cost[v][u]);
        }
    }
    return res;
}
double dis(int a,int b){
    return sqrt((p[a].first-p[b].first)*(p[a].first-p[b].first)+(p[a].second-p[b].second)*(p[a].second-p[b].second));
}
int main(){
    freopen("1.txt","r",stdin);
    int M;
    while(~scanf("%d%d",&V,&M)){
        for(int i=0;i<V;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            p[i].first=a;
            p[i].second=b;
        }
        double total=0;
        for(int i=0;i<M;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            a--;b--;
            cost[a][b]=cost[b][a]=-dis(a,b);
            total+=-cost[b][a];
        }
        printf("%.3f",total+prim());
    }
    return 0;
}
