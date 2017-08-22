#include<cstdio>

using namespace std;
int a[10];
int dfs(int x,int l,int r){
    if(x==10)return 1;
    int a1=0,a2=0;
    if(a[x]>l)a1=dfs(x+1,a[x],r);
    if(a[x]>r)a2=dfs(x+1,l,a[x]);
    return a1||a2;
}
int main(){
    freopen("1.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<10;i++)scanf("%d",&a[i]);
        int x=dfs(0,0,0);
        printf("%s\n",x?"YES":"NO");
    }
}
