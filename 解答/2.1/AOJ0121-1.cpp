#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
map<string,int> dp;
const int dd[]={+4,-4,+1,-1};
queue<string> q;
bool is_in(int x){
   return x>=0&&x<=7;
}
void bfs(){
    string be="01234567";
    dp[be]=0;
    q.push(be);
    while(!q.empty()){
        string now=q.front();q.pop();
        int ze;
        for(int i=0;i<now.size();i++){
            if(now[i]=='0'){
                ze=i;break;
            }
        }
        for(int i=0;i<4;i++){
            if(ze==3&&i==2)continue;
            if(ze==4&&i==3)continue;
            if(!is_in(ze+dd[i]))continue;
            string xxx=now;
            swap(xxx[ze],xxx[ze+dd[i]]);
            if(!dp.count(xxx)){
                dp[xxx]=dp[now]+1;
                q.push(xxx);
            }
        }
    }

}

int main()
{
    bfs();
    string line;
    while(getline(cin,line)){
        line.erase(remove(line.begin(),line.end(),' '),line.end());
        cout<<dp[line]<<endl;
    }
    return 0;
}
