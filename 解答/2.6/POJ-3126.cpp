#include<cstdio>
#include<iostream>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
#define MAX_N 9999+10
int prime[MAX_N];
bool is_prime[MAX_N+1];
bool is_vis[MAX_N+1];
queue<string> q;
queue<int> qq;
int sieve(int n){
    int p=0;
    for(int i=0;i<=n;i++)is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            prime[p++]=i;
            for(int j=2*i;j<=n;j+=i)is_prime[j]=false;
        }
    }
    return p;
}
int cti(string& a){
    int ans=0;
    for(int i=0;i<4;i++){
        ans=ans*10+a[i]-'0';
    }
    return ans;
}
void solve(string& a,string& b){
    while(!q.empty()){
        q.pop();qq.pop();
    }
    memset(is_vis,false,sizeof(is_vis));
    q.push(a);
    qq.push(0);
    is_vis[cti(a)]=true;
    while(!q.empty()){
        string s=q.front();q.pop();
        int step=qq.front();qq.pop();
        if(s==b){
            cout<<step<<endl;
            return ;
        }
        for(int i=0;i<10;i++){
            for(int j=0;j<4;j++){
                if(i==0&&j==0)continue;
                string ss=s;
                ss[j]=i+'0';
                int ttt=cti(ss);
                //cout<<ttt<<" "<<step<<endl;
                if(is_prime[ttt]&&!is_vis[ttt]){
                    is_vis[ttt]=true;
                    q.push(ss);
                    qq.push(step+1);
                }
            }
        }
    }
    cout<<"Impossible"<<endl;
}

int main(){
   // freopen("1.txt","r",stdin);
   // freopen("2.txt","w",stdout);
    int T;
    cin>>T;
    sieve(10000);
    while(T--){
        string a,b;
        cin>>a>>b;
        solve(a,b);
    }
    return 0;
}
