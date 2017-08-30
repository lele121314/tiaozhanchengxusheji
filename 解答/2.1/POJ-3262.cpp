#include<cstdio>
#include<algorithm>
using namespace std;

struct e{
    long long t,d;
    bool operator<(const e &b) const{
        return (double)d/(double)t>(double)b.d/(double)b.t;
    }
}flow[100002];


int main(){
    int n;
    scanf("%d",&n);
    long long total=0;
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&flow[i].t,&flow[i].d);
        total+=flow[i].d;
    }
    sort(flow,flow+n);
    long long ans=0;
    for(int i=0;i<n;i++){
        total-=flow[i].d;
        ans+=flow[i].t*total;
    }
    printf("%lld",ans*2);
}
