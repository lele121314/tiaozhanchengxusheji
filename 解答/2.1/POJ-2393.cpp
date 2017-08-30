#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
long long  n,s;
long long ans=0;
struct node{
    int v,id;
    bool operator <(const node &b) const{
        return v>b.v+(id-b.id)*s;
    }
};
priority_queue<node> Q;

int main(){
    while(!Q.empty())Q.pop();
    freopen("1.txt","r",stdin);
    cin>>n>>s;
    for(int i=0;i<n;i++){
        long long c,y;
        cin>>c>>y;
        struct node xxx;
        xxx.id=i;
        xxx.v=c;
        Q.push(xxx);
        struct node temp=Q.top();
        //ans=temp.v;
        ans+=(temp.v-(temp.id-i)*s)*y;
        //cout<<(temp.id-i)*s<<endl;
       // cout<<ans<<endl;
    }
    cout<<ans;
   // printf("%lld",ans);
}
