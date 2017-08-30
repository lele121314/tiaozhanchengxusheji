#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int s1,s2,s3,s4,s5,s6;
    while(scanf("%d%d%d%d%d%d",&s1,&s2,&s3,&s4,&s5,&s6)!=EOF&& s1+s2+s3+s4+s5+s6){
        int packets=0;
        packets+=s6;
        packets+=s5;
        s1=max(0,s1-11*s5);

        packets+=s4;
        if(s2<5*s4)s1=max(0,s1-(5*s4-s2));
        s2=max(0,s2-5*s4);

        packets+=(s3+3)/4;
        s3%=4;
        if(s3==1){
            if(s2<5)s1=max(0,s1-(27-4*s2));
            else s1=max(0,s1-7);
            s2=max(0,s2-5);
        }
        else if(s3==2){
            if(s2<3)s1=max(0,s1-(18-4*s2));
            else s1=max(0,s1-6);
            s2=max(0,s2-3);
        }
        else if(s3==3){
            if(s2<1)s1=max(0,s1-(9-4*s2));
            else s1=max(0,s1-5);
            s2=max(0,s2-1);
        }
        packets+=(s2+8)/9;
        s2%=9;
        if(s2)s1=max(0,s1-(36-4*s2));

        packets+=(s1+35)/36;
        printf("%d\n",packets);
    }
    return 0;
}
