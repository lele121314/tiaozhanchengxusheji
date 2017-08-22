#include<cstdio>
#include<iostream>
#include<sstream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int ans;
string line;
int main(){
    freopen("1.txt","r",stdin);
    int t;
    cin>>t;
    getline(cin,line);
    while(t--){
        ans=2147483647;
        getline(cin,line);
        line.erase(remove(line.begin(),line.end(),' '),line.end());
        sort(line.begin(),line.end());
        int len=line.length();
        do{
            if(line[0]=='0')continue;
            else if(line[len/2]=='0'&&len>2)continue;
            int l=0,r=0;
            for(int i=0;i<len/2;i++){
                l=l*10+line[i]-'0';
            }
            for(int i=len/2;i<len;i++){
                r=r*10+line[i]-'0';
            }
            ans=min(ans,abs(l-r));
        }while(next_permutation(line.begin(),line.end()));
        printf("%d\n",ans);
    }
    return 0;
}

