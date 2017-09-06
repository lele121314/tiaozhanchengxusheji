#include<iostream>
#include<algorithm>
#include<queue>
#include<limits>
#include<functional>
using namespace std;

#define MAX_COW 100000+16

int N,C,F;
pair<int,int> cow[MAX_COW];
int lower[MAX_COW],upper[MAX_COW];

int main(){
    cin>>N>>C>>F;
    int half=N/2;
    for(int i=0;i<C;i++)cin>>cow[i].first>>cow[i].second;
    sort(cow,cow+C);
    {
        int total=0;
        priority_queue<int> q;
        for(int i=0;i<C;i++){
            lower[i]=q.size()==half?total:0x3f3f3f3f;
            q.push(cow[i].second);
            total+=cow[i].second;
            if(q.size()>half)total-=q.top(),q.pop();
        }
    }
    {
        int total=0;
        priority_queue<int> q;
        for(int i=C-1;i>=0;i--){
            upper[i]=q.size()==half?total:0x3f3f3f3f;
            q.push(cow[i].second);
            total+=cow[i].second;
            if(q.size()>half)total-=q.top(),q.pop();
        }
    }
    int result=0;
    for(int i=C-1;i>=0;i--){
        if(lower[i]+cow[i].second+upper[i]<=F){
            result=cow[i].first;
            break;
        }
    }
    cout<<result<<endl;
    return 0;
}
