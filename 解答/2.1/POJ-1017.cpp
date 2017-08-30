#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;
int ans;
priority_queue<int > q;
priority_queue<int > a;
bool input(){
    int x=0;
    for(int i=1;i<=6;i++){
        int qqq;
        if(scanf("%d",&qqq)==EOF)return false;
        for(int j=0;j<qqq;j++)a.push(i);
        if(qqq==0)x++;
    }
//    printf("%d\n\n",a.size());
//    while(!a.empty()){
//        printf("%d\n",a.top());
//        a.pop();
//    }
    if(x==6)return false;
    return true;
}
void solve(){
    while(!a.empty()){

        if(q.size()==0){
            ans++;
            q.push(6);
        }

        int now=a.top();a.pop();

        int qq=q.top();q.pop();

        if(now>qq){
            ans++;
            q.push(qq);
            int num=(36-now*now)/((6-now)*(6-now));
            for(int i=0;i<num;i++)q.push(6-now);
        }
        else if(now==qq){

        }
        else{
            int num=(qq*qq-now*now)/((qq-now)*(qq-now));
            for(int i=0;i<num;i++)q.push(qq-now);
        }

    }
    printf("%d\n",ans);

}
int main(){
    freopen("1.txt","r",stdin);

    while(input()){
        ans=0;
        while(!q.empty())q.pop();
        solve();
    }
    return 0;
}
