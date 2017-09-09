#include<cstdio>
#include<algorithm>
using namespace std;

int l,n,m;
int x[50050];
bool C(int d){
        int last=0;
        for(int i=1;i<n-m;i++){
            int crt=last+1;
            while(crt<n&&x[crt]-x[last]<d){
                crt++;
            }
            if(crt==n)return false;
            last=crt;
        }
    return true;
}
int main(){
    scanf("%d%d%d",&l,&n,&m);
    x[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&x[i]);
    }
    n++;
    x[n]=l;
    n++;
    sort(x,x+n);
    int lb=0,ub=l+1;
    while(ub-lb>1){
        int mid=(lb+ub)/2;
        if(C(mid))lb=mid;
        else ub=mid;
    }
    printf("%d",lb);
}
