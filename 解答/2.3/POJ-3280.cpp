#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX_N=200;
const int MAX_M=2000+500;
int add[MAX_N];
int dp[MAX_M][MAX_M];
int main(){
    int n,m;
    string s;
    while(cin>>n>>m){
        cin>>s;
        char c;
        int x,y;
        for(int i=0;i<n;i++){
            cin>>c>>x>>y;
            add[c]=min(x,y);
        }
        memset(dp,0,sizeof(dp));
         for(int k=1;k<s.size();k++)
        {
            for(int i=0,j=k;j<s.size();i++,j++)
            {
                dp[i][j]=0x3f3f3f3f;
                if(s[i]==s[j])
                    dp[i][j]=dp[i+1][j-1];
                else
                {
                    dp[i][j]=min(dp[i+1][j] + add[s[i]],dp[i][j]);
                    dp[i][j]=min(dp[i][j-1] + add[s[j]],dp[i][j]);
                }
            }
        }

        cout<<dp[0][s.size()-1]<<endl;
    }
    return 0;
}
