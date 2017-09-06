#include<cstdio>
#include<iostream>
#include<cstring>
const int MAX_N=100000+16;
int a[MAX_N*2];
bool mark[MAX_N*2];
int N,Q;
int main(){
    freopen("1.txt","r",stdin);
    while(scanf("%d%d",&N,&Q)!=EOF){
        if(N==0&&Q==0)break;
        memset(mark,false,sizeof(bool)*(N+10));
        a[1]=0;
        mark[1]=1;
        for(int i=2;i<=N;i++){
            scanf("%d",&a[i]);
        }
        long ans=0;
        while(Q--){
            char c[2];
            int x;
            scanf("%s %d",c,&x);
            if(c[0]=='Q'){
                while(!mark[x]){
                    x=a[x];
                }
                ans+=x;
            }
            else {
                mark[x]=true;
            }
        }
        printf("%ld\n",ans);
    }
    return 0;
}
