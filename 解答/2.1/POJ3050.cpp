#include<cstdio>
#include<cstring>
using namespace std;

int a[6][6];
bool vis[1000000];
int ans=0;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
bool is_in(int x,int y){
    return x>=1&&x<=5&&y>=1&&y<=5;
}
void dfs(int x,int y,int n,int num){
    if(n==5){
        if(!vis[num]){
            vis[num]=true;
            ans++;

        }
        return;
    }
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=dy[i]+y;
        if(is_in(xx,yy))dfs(xx,yy,n+1,num*10+a[xx][yy]);
    }
}
int main(){
    freopen("1.txt","r",stdin);
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            dfs(i,j,0,a[i][j]);
        }
    }
    printf("%d",ans);
}
