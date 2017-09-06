#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define MAX_V 1000 + 16
#define INF 0x3f3fffff
using namespace std;

int cost[MAX_V][MAX_V];
int d[MAX_V],d1[MAX_V];
bool used[MAX_V];
int V;

void dijkstra1(int s){
    fill(d,d+V,INF);
    fill(used,used+V,false);
    d[s]=0;
    while(true){
        int v=-1;
        for(int u=0;u<V;u++){
            if(!used[u]&&(v==-1||d[u]<d[v]))v=u;
        }
        if(v==-1)break;
        used[v]=true;
        for(int u=0;u<V;u++){
            d[u]=min(d[u],d[v]+cost[v][u]);
        }
    }
}
void dijkstra2(int s){
    fill(d1,d1+V,INF);
    fill(used,used+V,false);
    d1[s]=0;
    while(true){
        int v=-1;
        for(int u=0;u<V;u++)if(!used[u]&&(v==-1||d1[u]<d1[v]))v=u;
        if(v==-1)break;
        used[v]=true;
        for(int u=0;u<V;u++){
            d1[u]=min(d1[u],d1[v]+cost[u][v]);
        }
    }
}
int main(){
    freopen("1.txt","r",stdin);
    int M,X;
    cin>>V>>M>>X;
    X--;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cost[i][j]=INF;
        }
    }
    while(M--){
        int a,b,t;
        cin>>a>>b>>t;
        a--;b--;
        cost[a][b]=t;
    }
    dijkstra1(X);
    dijkstra2(X);
    int maxx=0;
    for(int i=0;i<V;i++){
        //if(d[i]==INF||d1[i]==INF)continue;
        maxx=max(maxx,d[i]+d1[i]);
        //cout<<d1[i]<<endl;
    }
    cout<<maxx;
    return 0;
}
