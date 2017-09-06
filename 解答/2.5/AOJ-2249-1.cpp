#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX_V 10006
#define INF 0x3fffffff
using namespace std;
struct edge{
    int to,cost,dis;
    };
typedef pair<int,int> P;
int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dij(int s){
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+V,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
        P p=que.top();que.pop();
        int v=p.second;
        if(d[v]<p.first)continue;
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
    int ans=0;

    for(int i=1;i<V;i++){
        int mimcost=INF;
        for(int j=0;j<G[i].size();j++){
            if(d[G[i][j].to]+G[i][j].cost==d[i]&&G[i][j].dis<mimcost){

                mimcost=G[i][j].dis;
                //cout<<mimcost<<endl;
            }
        }
        //cout<<mimcost<<endl;
        ans+=mimcost;
    }
    cout<<ans<<endl;

}

int main(){
    freopen("1.txt","r",stdin);
    int M;
    while(cin>>V>>M){
        if(V==0&&M==0)break;
        for(int i=0;i<V;i++)G[i].clear();
        while(M--){
            int a,b,t,c;
            cin>>a>>b>>t>>c;
            a--;b--;
            edge tmp;
            tmp.to=b;
            tmp.cost=t;
            tmp.dis=c;
            G[a].push_back(tmp);
            tmp.to=a;
            G[b].push_back(tmp);
        }
        dij(0);
    }
    return 0;
}
