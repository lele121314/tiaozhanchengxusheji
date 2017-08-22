#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int h,w,n;
char adj[1005][1005];
bool vis[1005][1005];
int ans,sx,sy;
queue<int> q;
bool is_in(int x,int y){
    if(x>=0&&x<h&&y>=0&&y<w)return true;
    return false;
}
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
void bfs(int n){
    while(!q.empty())q.pop();
    memset(vis,false,sizeof(vis));
    q.push(sx);q.push(sy);q.push(0);
    vis[sx][sy]=true;
    while(!q.empty()){
        int x=q.front();q.pop();
        int y=q.front();q.pop();
        int step=q.front();q.pop();
        if(adj[x][y]==n){
            //printf("ans:%d\n",ans);
            ans+=step;
            sx=x;sy=y;
            return ;
        }
        for(int i=0;i<4;i++){
            int xx=x+dx[i],yy=y+dy[i];
            if(is_in(xx,yy)&&!vis[xx][yy]&&adj[xx][yy]!='X'){
                vis[xx][yy]=true;
                q.push(xx);q.push(yy);q.push(step+1);
            }
        }

    }

}
int main(){
    freopen("1.txt","r",stdin);
    while(scanf("%d%d%d",&h,&w,&n)!=EOF){
        for(int i=0;i<h;i++){
            scanf("%s",&adj[i]);
            for(int j=0;j<w;j++){
                if(adj[i][j]=='S'){
                    sx=i;sy=j;
                }
            }
        }
        ans=0;
        for(char i='1';i<=n+'0';i++){
            bfs(i);
        }
        printf("%d\n",ans);
    }
}
