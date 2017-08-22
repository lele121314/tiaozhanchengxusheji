#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[11];
int n,sum;
bool solve(){
    int b[11],c[11];
    memcpy(b,a,sizeof(a));
    for(int i=n;i>1;i--){
        for(int j=0;j<i-1;j++){
            c[j]=b[j]+b[j+1];
//            printf("%d ",c[j]);
        }
        memcpy(b,c,sizeof(c));
//        printf("\n");
    }
   // printf("%d\n",b[0]);
    if(b[0]==sum)return true;
    return false;
}
int main(){
    freopen("1.txt","r",stdin);
    while(cin>>n>>sum){
        for(int i=0;i<n;i++)a[i]=i+1;
        do{
//            for(int i=0;i<n-1;i++){
//                printf("%d ",a[i]);
//            }
//            printf("%d\n",a[n-1]);
            if(solve()){
                for(int i=0;i<n-1;i++){
                    printf("%d ",a[i]);
                }
                printf("%d",a[n-1]);
                break;
            }

        }while(next_permutation(a,a+n));
    }
    return 0;
}

