#include<cstdio>
#include<algorithm>
#include<cmath>
#define MAX_V 10000+100
#define MAX_E ((MAX_V*(MAX_V-1))/2)
using namespace std;

struct edge{
    int u,v;
    double cost;
};

bool cmp(const edge& e1,const edge& e2){
    return e1.cost<e2.cost;
}

edge es[MAX_E];
int V,E;
int par[MAX_V];
int rankk[MAX_V];
void init(int n){
    for(int i=0;i<n;i++){
        par[i]=i;
        rankk[i]=0;
    }
}
int find(int x){
    if(par[x]==x)return x;
    else return par[x]=find(par[x]);
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    if(rankk[x]<rankk[y]){
        par[x]=y;
    }
    else {
        par[y]=x;
        if(rankk[x]==rankk[y])rankk[x]++;
    }
}
bool same(int x,int y){
    return find(x)==find(y);
}

double Keu(){
    sort(es,es+E,cmp);
    init(V);
    double res=0;
    for(int i=0;i<E;i++){
        edge e=es[i];
        if(!same(e.u,e.v)){
            unite(e.u,e.v);
            res+=e.cost;
        }
    }
    return res;
}

pair<int,int> p[MAX_V];
double dis(int a,int b){
    return sqrt((p[a].first-p[b].first)*(p[a].first-p[b].first)+(p[a].second-p[b].second)*(p[a].second-p[b].second));
}
int main(){
    freopen("1.txt","r",stdin);
    while(~scanf("%d%d",&V,&E)){
        for(int i=0;i<V;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            p[i].first=a;
            p[i].second=b;
        }
        double total=0;
        for(int i=0;i<E;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            a--;b--;
            es[i].u=a;
            es[i].v=b;
            es[i].cost=-dis(a,b);

            total+=-es[i].cost;
        }
        printf("%.3f",total+Keu());
    }
    return 0;
}
