#include<cstdio>
#include<iostream>
using namespace std;
long long gcd(long long a,long long b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
int main(){
    long long a,b;
    while(cin>>a>>b){
        long long x;
        if(a>b)x=gcd(a,b);
        else x=gcd(b,a);
        cout<<x<<" "<<a/x*b<<endl;

    }
}
