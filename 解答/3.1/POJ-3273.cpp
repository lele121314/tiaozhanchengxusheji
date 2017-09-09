#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ULL;
int n,m;
ULL x[100500];
bool C(int d){
    int pr=1;
    ULL ex=0;
    for(int i=0;i<n;i++){
        ex+=x[i];
        if(ex>d){
            ex=x[i];
            pr++;
        }
    }
    if(pr>m)return true;
    return false;
}
int main(){
    cin>>n>>m;
    ULL ub=0;
    for(int i=0;i<n;i++){
        cin>>x[i];
        ub+=x[i];
    }
    ULL lb = *max_element(x, x + n);
    while(ub>lb){
        ULL mid=(lb+ub)/2;
        if(C(mid))lb=mid+1;
        else ub=mid;
    }
    cout<<lb;
}
