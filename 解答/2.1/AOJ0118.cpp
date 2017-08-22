#include<cstdio>
#include<cstring>
using namespace std;

int w,h;
char adj[105][105];
bool vis[105][105];
int ans;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
bool is_in(int x,int y){
    if(x>=0&&x<h&&y>=0&&y<w)return true;
    return false;
}
void dfs(int x,int y){
     vis[x][y]=true;
    for(int i=0;i<4;i++){
        int xx=dx[i]+x,yy=dy[i]+y;
        if(is_in(xx,yy)&&adj[xx][yy]==adj[x][y]&&!vis[xx][yy]){
            dfs(xx,yy);
        }
    }
}
int main(){
    freopen("1.txt","r",stdin);
    while(scanf("%d%d",&h,&w)!=EOF){
        if(w==0&&h==0)break;
        memset(vis,false,sizeof(vis));
        for(int i=0;i<h;i++){
            scanf("%s",adj[i]);
        }
        ans=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(!vis[i][j]){
                    ans++;

                    dfs(i,j);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
