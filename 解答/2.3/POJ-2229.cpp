#include<cstdio>
const int mo=1000000000;
int a[1000005];
int main(){
    int n;
    scanf("%d",&n);
    a[0]=0;a[1]=1;a[2]=2;
    for(int i=3;i<=n;i++){
        if(i%2==1){
            a[i]=a[i-1];
        }
        else{
            a[i]=(a[i-1]+a[i/2])%mo;
        }
    }
    printf("%d",a[n]);
}
