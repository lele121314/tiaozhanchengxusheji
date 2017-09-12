#include<cstdio>
#include<algorithm>
#include<iostream>
#include<algorithm>
using namespace std;

int n;
int a[100000+10];
int k;
bool C(int d){
    int x=0;
    for(int i=0;i<n;i++){
        int more=a[i]-d;
        if(more>0){
            x+=(more+k-1)/k;
        }
        if(x>d)return false;
    }
    return true;
}
int main(){
    freopen("1.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin>>n;
    int maxa=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    cin>>k;
    k--;
    if(!k){
        cout<<maxa<<endl;
        return 0;
    }
    int lb=0,ub=maxa+1;
    while(ub-lb>1){
        int mid=(lb+ub)/2;
        if(C(mid))ub=mid;
        else lb=mid;
    }
    cout<<ub<<endl;
    return 0;

}
