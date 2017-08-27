#include<cstdio>
#include<algorithm>
using namespace std;
const int maxt=1000000+5;
int N,T;
pair<int ,int> itv[maxt];
bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first!=b.first)return a.first<b.first;
    return a.second>b.second;
}
int solve(){
    int ans=0,en=0;
    int index=0;
    while(en<T){
        int beg=en+1;
        for(int i=index;i<N;i++){
            if(itv[i].first<=beg){
                if(itv[i].second>=beg){
                    en=max(en,itv[i].second);
                }

            }
            else
            {
                index=i;
                break;
            }

        }
        if(beg>en){
                return -1;
            }
            else ans++;
    }

    return ans;
}
int main(){
    freopen("1.txt","r",stdin);
    scanf("%d%d",&N,&T);
    for(int i=0;i<N;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        itv[i].first=a;
        itv[i].second=b;
    }
    sort(itv,itv+N,cmp);
    printf("%d\n",solve());
    return 0;
}
