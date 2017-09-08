#include<cstdio>
#include<iostream>
using namespace std;

typedef long long ll;
ll mod_pow(ll x,ll n,ll mod){
    ll res=1;
    while(n>0){
        if(n&1)res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}


int main(){
    int Z;
    cin>>Z;
    while(Z--){
        int M,H;
        cin>>M>>H;
        int ans=0;
        while(H--){
            int a,b;
            cin>>a>>b;
            ans+=mod_pow(a,b,M);
        }
        ans%=M;
        cout<<ans<<endl;
    }
    return 0;
}
