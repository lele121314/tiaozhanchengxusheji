#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAX_V 516
int d[MAX_V][MAX_V];
int x[MAX_V];
int N,M;
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
    while(cin>>N>>M){
        memset(d,0x3f,MAX_V*MAX_V*sizeof(int));
        for(int i=0;i<N;i++){
            d[i][i]=0;
        }
        int num;
        while(M--){
            cin>>num;
            for(int i=0;i<num;i++){
                cin>>x[i];
            }
            for(int i=0;i<num;i++){
                for(int j=i+1;j<num;j++){
                    d[x[i]-1][x[j]-1]=1;
                    d[x[j]-1][x[i]-1]=1;
                }
            }
        }
        warshall_floyd();
        int ans=0x3f3f3f3f;
        for(int i=0;i<N;i++){
            int sum=0;
            for(int j=0;j<N;j++){
                sum+=d[i][j];
            }
        ans=min(ans,sum);
        }
        cout<<(100*ans/(N-1))<<endl;
    }
    return 0;
}
