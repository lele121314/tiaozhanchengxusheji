#include<cstdio>
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
bool is_prime(const int& n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return n!=1;
}

int main(){
    ll p,a;
    freopen("1.txt","r",stdin);
    while(~scanf("%lld%lld",&p,&a)){
        if(p==0&&a==0)break;
        if(is_prime(p)){
                printf("no\n");
                continue;
        }
        ll t=mod_pow(a,p,p);
        printf("%s\n",(t==a?"yes":"no"));
    }
    return 0;
}
