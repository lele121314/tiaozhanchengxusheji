#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#define MAX_V 10000+100
#define MAX_E ((MAX_V*(MAX_V-1))/2)
using namespace std;

struct edge{
    int u,v;
    int cost;
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
int Keu(){
    sort(es,es+E,cmp);
    init(V);
    int res=0;
    for(int i=0;i<E;i++){
        edge e=es[i];
        if(!same(e.u,e.v)){
            unite(e.u,e.v);
            res=max(e.cost,res);
        }
    }
    return res;
}


int main(){
    freopen("1.txt","r",stdin);
    while(~scanf("%d%d",&V,&E)){
        for(int i=0;i<E;i++){
            int a,b,t;
            scanf("%d%d%d",&a,&b,&t);
            a--;b--;
            es[i].u=a;
            es[i].v=b;
            es[i].cost=t;
        }
        printf("%d",Keu());
    }
    return 0;
}
