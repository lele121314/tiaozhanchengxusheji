#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int n,ans;
double d;
vector<pair<double , double > > p;
double len2(double z,double y){
    return sqrt(z*z-y*y);
}
int main(){
    freopen("1.txt","r",stdin);
    int kase=0;
    while(scanf("%d%lf",&n,&d)!=EOF){
        if(n==0&&d==0)break;
        printf("Case %d: ",++kase);
        p.clear();
        ans=0;
        bool haveans=true;
        for(int i=0;i<n;i++){
            double a,b;
            scanf("%lf%lf",&a,&b);
            if(b>d)haveans=false;
            pair<double , double > x;
            double dx=len2(d,b);
            x.first=a-dx;x.second=a+dx;
            p.push_back(x);
        }
        if(!haveans){
            printf("%d\n",-1);
            continue;
        }
        sort(p.begin(),p.end());
        //for(int i=0;i<n;i++)printf("%lf %lf\n",p[i].first,p[i].second);
        double temp=-100000000;


        for(int i=0;i<n;i++){
            if(p[i].first>temp){
                ans++;
                temp=p[i].second;
            }
            else if(p[i].second<temp){
                temp=p[i].second;
            }
        }
        printf("%d\n",ans);
    }
}
