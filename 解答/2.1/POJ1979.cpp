#include<cstdio>
#include<cstring>
using namespace std;

int w,h;
char adj[25][25];
int ans;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
bool is_in(int x,int y){
    if(x>=0&&x<h&&y>=0&&y<w)return true;
    return false;
}
void dfs(int x,int y){

    for(int i=0;i<4;i++){
        int xx=dx[i]+x,yy=dy[i]+y;
        if(is_in(xx,yy)&&adj[xx][yy]=='.'){
            ans++;
            adj[xx][yy]='#';
            dfs(xx,yy);
        }
    }

}
inline void solve(){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(adj[i][j]=='@'){
                ans=0;
                adj[i][j]='#';
                ans++;
                dfs(i,j);
                printf("%d\n",ans);
                return;
            }
        }
    }
}
int main(){
    freopen("1.txt","r",stdin);
    while(scanf("%d%d",&w,&h)!=EOF){
        if(w==0&&h==0)break;
        for(int i=0;i<h;i++){
            scanf("%s",adj[i]);
        }
        solve();
    }
    return 0;
}
