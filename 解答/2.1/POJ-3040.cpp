#include<cstdio>
#include<cstring>
#include<algorithm>

#define v first
#define b second
using namespace std;

typedef pair<int, int> node;

bool cmp(node num1,node num2){
    return num1.v>num2.v;
}

int main(){
    int n,c;

    node val[30];
    scanf("%d%d",&n,&c);
    for(int i=0;i<n;i++){
        scanf("%d%d",&val[i].v,&val[i].b);
    }
    sort(val,val+n,cmp);

    int i=0;
    int count=0;
    for(;i<n;i++){
        if(val[i].v>=c){
            count+=val[i].b;
            val[i].b=0;
        }
        else break;
    }
    int need[30]={0};
    while(1){
        int sum=c;
        memset(need,0,sizeof(need));
        for(int j=i;j<n;j++){
            if(val[j].b&&sum>0){
                need[j]+=min(val[j].b,sum/val[j].v);
                sum-=need[j]*val[j].v;
            }
        }

        if(sum>0){
            for(int j=n-1;j>=i;j--){
                if(val[j].b&&sum>0){
                    int mi;
                    mi=min(val[j].b-need[j],(sum+val[j].v-1)/val[j].v);
                    if(mi>0){
                        sum-=mi*val[j].v;
                        need[j]+=mi;
                    }
                }
            }
        }

        if(sum>0)break;
        int x=1e9+1;
        for(int j=i;j<n;j++){
            if(need[j]){
                x=min(x,val[j].b/need[j]);
            }
        }
        count+=x;
        for(int j=i;j<n;j++){
            if(need[j]){
                val[j].b-=x*need[j];
            }
        }
    }
    printf("%d\n",count);
    return 0;
}
