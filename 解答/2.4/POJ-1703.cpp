#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX_N 1000000*2+16
int par[MAX_N];
int rankk[MAX_N];
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
    if(rankk[x]<rankk[y])par[x]=y;
    else {
        par[y]=x;
        if(rankk[x]==rankk[y])rankk[x]++;
    }
}
int main(){
    freopen("1.txt","r",stdin);
    //ios::sync_with_stdio(false);
    int T;
    scanf("%d",&T);
    while(T--){
        int N,M;
        scanf("%d%d",&N,&M);
        init(N*2);
        int index=1;
        while(M--){
            char c[2];int x,y;
            scanf("%s %d %d",c,&x,&y);
            if(c[0]=='D'){
                unite(x,y+N);
                unite(y,x+N);
            }
            else{
                if(find(x)==find(y)){
                    cout<<"In the same gang.\n";
                    continue;
                }
                else if(find(x)==find(N+y)){
                    cout<<"In different gangs.\n";
                    continue;
                }
                else{
                    cout<<"Not sure yet.\n";
                    continue;
                }
            }
        }


    }
    return 0;
}
