#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
priority_queue<double> q;


int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        double x;
        scanf("%lf",&x);
        q.push(x);
    }
    while(q.size()!=1){
        double a=q.top();q.pop();
        double b=q.top();q.pop();
        double tem=2*sqrt(a*b);
        q.push(tem);
    }
    printf("%.3f\n",q.top());
    q.pop();
    return 0;
}
