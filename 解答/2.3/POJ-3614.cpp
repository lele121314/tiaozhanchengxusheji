#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

pair<int,int> cow[2500+16];
pair<int,int> bottle[2500+16];
priority_queue<int , vector<int> ,greater<int> > q;

int main(){
    int c,l;
    scanf("%d%d",&c,&l);
    for(int i=0;i<c;i++){
        scanf("%d%d",&cow[i].first,&cow[i].second);
    }
    for(int i=0;i<l;i++){
        scanf("%d%d",&bottle[i].first,&bottle[i].second);
    }
    sort(cow,cow+c);
    sort(bottle,bottle+l);
    int cur=0;
    int result=0;
    for(int i=0;i<l;i++){
        while(cur<c&&cow[cur].first<=bottle[i].first){
            q.push(cow[cur].second);
            cur++;
        }
        while(!q.empty()&&bottle[i].second){
            int maxSPF=q.top();q.pop();
            if(maxSPF>=bottle[i].first){
                result++;
                --bottle[i].second;
            }
        }
    }
    printf("%d\n",result);
    return 0;
}
