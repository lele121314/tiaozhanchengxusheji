#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAX_V 516
int d[MAX_V][MAX_V];
int x[MAX_V];
int N,M,W;
void warshall_floyd(){
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}
int main(){
    freopen("1.txt","r",stdin);
    int T;
    cin>>T;
    while(T--){
        cin>>N>>M>>W;
        memset(d,0x3f,MAX_V*MAX_V*sizeof(int));
        for(int i=0;i<N;i++){
            d[i][i]=0;
        }
        int num;
        while(M--){
            int x,y,t;
            cin>>x>>y>>t;
            d[x-1][y-1]=t;
        }
        while(W--){
            int x,y,t;
            cin>>x>>y>>t;
            d[x-1][y-1]=-t;
        }
        warshall_floyd();
        int ans=0x3f3f3f3f;
        for(int i=0;i<N;i++){
            int sum=d[i][i];

        ans=min(ans,sum);
        }
        cout<<(ans<0?"YES\n":"NO\n");
    }
    return 0;
}

