#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
pair<int,int> p[50002];
int ans[50002];
int t[1000001];
int main(){
    freopen("1.txt","r",stdin);
    scanf("%d",&n);
    memset(ans,0,sizeof(ans));
    memset(t,0,sizeof(ans));
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        p[i].first=a;p[i].second=b;
    }
    sort(p,p+n);
    int room=1;
    t[room]=0;
    room++;
    ans[0]=1;
    for(int i=1;i<n;i++){
        bool flag=false;
        for(int j=1;j<room;j++){
            if(p[t[j]].second<=p[i].first){
                t[j]=i;
                ans[i]=j;
                flag=true;
                break;
            }
        }
        if(!flag){
            t[room]=i;
            ans[i]=room;
            room++;
        }
    }
    printf("%d\n",room-1);
    for(int i=0;i<n;i++){
        printf("%d\n",ans[i]);
    }
}
