#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
long long gcd(long long a,long long b){
    long long tmp;
    while(b!=0){
        a%=b;
        tmp=a;
        a=b;
        b=tmp;
    }
    return a;
}
int main(){
    long long x,y;
    while(cin>>x>>y){
        long c=y/x;
        for(long i=sqrt(c);i>=1;i--){
            if(c%i==0&&gcd(i,c/i)==1){
                cout<<(x*i)<<" "<<y/i<<endl;
                break;
            }
        }

    }
}
