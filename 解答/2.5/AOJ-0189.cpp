#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX_V 11
int d[MAX_V][MAX_V];
int v;

int x[MAX_V];

void warshall_floyd(){
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}
int main(){
    int E;
    while(cin>>E,E){
        memset(d,0x3f,MAX_V*MAX_V*sizeof(int));
        for(int i=0;i<MAX_V;i++){
            d[i][i]=0;
        }
        v=0;
        for(int i=0;i<E;i++){
            int x,y,cost;
            cin>>x>>y>>cost;
            d[x][y]=cost;
            d[y][x]=cost;
            v=max(v,max(x,y)+1);
        }
        warshall_floyd();
        memset(x,0,sizeof(int)*v);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                x[i]+=d[i][j];
            }
        }
        int ans=min_element(x,x+v)-x;
        cout<<ans<<" "<<x[ans]<<endl;
    }
    return 0;
}
