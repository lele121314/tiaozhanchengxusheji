#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define MAX_V 10000 + 16
#define INF 0x3f3fffff
using namespace std;

int cost[MAX_V][MAX_V];
int cc[MAX_V][MAX_V];
int d[MAX_V],d1[MAX_V];
bool used[MAX_V];
int V;

void dijkstra1(int s){
    fill(d,d+V,INF);
    fill(used,used+V,false);
    d[s]=0;
    d1[s]=0;
    while(true){
        int v=-1;
        for(int u=0;u<V;u++){
            if(!used[u]&&(v==-1||d[u]<d[v]))v=u;
        }
        if(v==-1)break;
        used[v]=true;
        for(int u=0;u<V;u++){
            if(d[u]>d[v]+cost[v][u]){
                d[u]=d[v]+cost[v][u];
            }
        }
    }
    int ans=0;

    for(int i=0;i<V;i++){
        int mimcost=INF;
        for(int j=0;j<V;j++){
            if(d[j]+cost[i][j]==d[i]&&cc[i][j]<mimcost){

                mimcost=cc[i][j];
                //cout<<mimcost<<endl;
            }
        }
        //cout<<mimcost<<endl;
        if(mimcost!=INF)ans+=mimcost;
    }
    cout<<ans<<endl;
}

int main(){
    freopen("1.txt","r",stdin);
    int M;
    while(cin>>V>>M){
        if(V==0&&M==0)break;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                cost[i][j]=INF;
            }
        }
        while(M--){
            int a,b,t,c;
            cin>>a>>b>>t>>c;
            a--;b--;
            cost[a][b]=t;
            cost[b][a]=t;
            cc[a][b]=c;
            cc[b][a]=c;
        }
        dijkstra1(0);
    }
    return 0;
}

