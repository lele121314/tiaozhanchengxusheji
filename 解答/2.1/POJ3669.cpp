#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
bool vis[310][310];
int adj[310][310];
int m;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,-1,1};
queue<int> q;
bool is_in(int x,int y){
    if(x>=0&&x<=301&&y>=0&&y<=301)return true;
    return false;
}
void print(int x,int y,int t){
    if(adj[x][y]==-1||adj[x][y]>t)adj[x][y]=t;
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(is_in(xx,yy)){
            if(adj[xx][yy]==-1||adj[xx][yy]>t)adj[xx][yy]=t;
        }
    }
}
void solve(){
    q.push(0);q.push(0);q.push(0);
    vis[0][0]=true;
    while(!q.empty()){
        int x=q.front();q.pop();
        int y=q.front();q.pop();
        int t=q.front();q.pop();
        if(adj[x][y]==-1){
            printf("%d",t);
            return ;
        }
        for(int i=0;i<4;i++){
            int xx=x+dx[i],yy=y+dy[i];
            if(is_in(xx,yy)&&!vis[xx][yy]&&(adj[xx][yy]==-1||adj[xx][yy]>t+1)){
                vis[xx][yy]=true;
                q.push(xx);q.push(yy);q.push(t+1);
            }
        }
    }
    printf("-1");
}
int main()
{
    freopen("1.txt","r",stdin);
    while(scanf("%d",&m)!=EOF){
        while(!q.empty())q.pop();
        memset(adj,-1,sizeof(adj));
        memset(vis,false,sizeof(vis));
        int x,y,t;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&x,&y,&t);
            print(x,y,t);
        }
        solve();
    }
    return 0;
}
