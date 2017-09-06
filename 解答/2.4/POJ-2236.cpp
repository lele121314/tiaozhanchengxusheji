#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX_N 1005
int N,D;
int par[MAX_N];
int rankk[MAX_N];
pair<int ,int> p[MAX_N];
vector<int> v;
void init(int n){
    for(int i=0;i<=n;i++){
        par[i]=0;
        rankk[i]=0;
    }
}

int find(int x){
    if(par[x]==x)return x;
    else return par[x]=find(par[x]);
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    if(rankk[x]<rankk[y])par[x]=y;
    else {
        par[y]=x;
        if(rankk[x]==rankk[y])rankk[x]++;
    }
}
bool dis(int x,int y){
    double t=(p[x].first-p[y].first)*(p[x].first-p[y].first)+(p[x].second-p[y].second)*(p[x].second-p[y].second);
    double xx=D*D;
    //cout<<x<<" "<<y<<" "<<t<<" "<<xx<<endl;
    return xx>=t;
}
void repair(int x){
    if(par[x]==0)par[x]=x;

    for(int i=0;i<v.size();i++){
        if(dis(x,v[i])){
            unite(x,v[i]);
            //cout<<x<<" "<<v[i]<<endl;
        }
    }
    v.push_back(x);
}
int main(){
    freopen("1.txt","r",stdin);
    cin>>N>>D;
    init(N);
    for(int i=1;i<=N;i++){
        cin>>p[i].first>>p[i].second;
    }
    char com;
    while(cin>>com){
        if(com=='O'){
            int x;
            cin>>x;
            repair(x);
        }
        else {
            int x,y;
            cin>>x>>y;
            int xx=find(x),yy=find(y);
            //cout<<xx<<yy<<endl;
            cout<<(xx!=0&&xx==yy?"SUCCESS":"FAIL")<<endl;
        }
    }
    return 0;
}
