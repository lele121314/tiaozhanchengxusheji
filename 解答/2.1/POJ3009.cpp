#include<cstdio>
using namespace std;

int adj[22][22];
int w,h;
int sx,sy,ex,ey;
int ans;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
bool is_in(int x,int y){
    if(x>=0&&x<w&&y>=0&&y<h)return true;
    return false;
}
void dfs(int x,int y,int step){
    if(step>=ans)return;
    //printf("444\n");
    if(x==ex&&y==ey){
        ans=step;
    }
    for(int i=0;i<4;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(!is_in(xx,yy)||adj[xx][yy]==1)continue;
        while(is_in(xx,yy)&&adj[xx][yy]!=1){
            if(xx==ex&&yy==ey){
                ans=step;
                return;
            }
            xx+=dx[i];
            yy+=dy[i];
        }
        if(!is_in(xx,yy))continue;
        adj[xx][yy]=0;
        dfs(xx-dx[i],yy-dy[i],step+1);
        adj[xx][yy]=1;
    }
}
void solve(){
    ans=11;
    dfs(sx,sy,1);
    printf("%d\n",ans==11?-1:ans);
}
int main(){
    freopen("1.txt","r",stdin);
    while(scanf("%d%d",&h,&w)!=EOF){
        if(w==0&&h==0)break;
        for(int i=0;i<w;i++){
            for(int j=0;j<h;j++){
                scanf("%d",&adj[i][j]);
                if(adj[i][j]==2){
                    sx=i;sy=j;
                }
                else if(adj[i][j]==3){
                    ex=i;ey=j;
                }
            }
        }
        solve();
    }
    return 0;
}
