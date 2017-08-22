#include<cstdio>
#include<iostream>
#include<sstream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int ans=2147483647;
char line[200];
int len;
vector<int> a;
bool vis[10];


void dfs(int mam,int son,int num,int l,int r){
    //cout<<mam<<endl;
    //cout<<son<<endl;

    if(l+r==a.size()&&num==0)return;
    if(l==0&&r==a.size()-a.size()/2&&num==0)return;
    if(l>0&&l%2==r%2){
        mam=mam*10+num;l--;
        if(abs(mam*pow(10,l)-son*pow(10,r))>ans)return;
    }
    else if(r>0){
        son=son*10+num;r--;
        //cout<<son*pow(10,r)<<endl;
        if(abs(mam*pow(10,l)-son*pow(10,r))>ans)return;
    }

    if(r==0&&l==0){
        int ssss=abs(mam-son);
        ans=min(ans,ssss);
        return;
    }
    for(int i=0;i<a.size();i++){
        if(!vis[a[i]]){
            vis[a[i]]=true;
            dfs(mam,son,a[i],l,r);
            vis[a[i]]=false;
        }

    }
}
void solve(int l,int r){
    for(int i=0;i<a.size();i++){
        vis[a[i]]=true;
        dfs(0,0,a[i],l,r,false);
        vis[a[i]]=false;
    }

}
int main(){
    freopen("1.txt","r",stdin);
    int t;
    scanf("%d",&t);
    gets(line);
    while(t--){
        memset(vis,false,sizeof(vis));
        a.clear();
        ans=2147483647;
        gets(line);
        len=strlen(line);

        for(int i=0;i<len;i++){
            if(line[i]!=' ')a.push_back(line[i]-'0');
        }
        sort(a.begin(),a.end());
        solve(a.size()/2,a.size()-a.size()/2);
        printf("%d\n",ans);
    }
    return 0;
}

