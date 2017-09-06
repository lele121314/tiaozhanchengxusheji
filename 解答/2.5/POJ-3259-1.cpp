#include<iostream>
#include<cstring>
using namespace std;

#define MAX_E (2500+200+16)*2

struct edge{
    int from,to,cost;
    edge(){}
    edge(int from,int to,int cost){
        this->from=from;
        this->to=to;
        this->cost=cost;
    }
};

edge es[MAX_E];

int d[MAX_E];

int V,E;

bool find_negative_loop(){
    memset(d,0,sizeof(d));
    for(int i=0;i<V;i++){
        for(int j=0;j<E;j++){
            edge e=es[j];
            if(d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
                if(i==V-1)return true;
            }
        }
    }
    return false;
}
int main(){
    int F;
    cin>>F;
    while(F--){
        int N,M,W;
        cin>>N>>M>>W;
        V=N;
        E=0;
        for(int i=0;i<M;i++){
            int from,to,cost;
            cin>>from>>to>>cost;
            from--;
            to--;
            es[E].from=from;
            es[E].to=to;
            es[E].cost=cost;
            E++;
            es[E].from=to;
            es[E].to=from;
            es[E].cost=cost;
            E++;

        }
        for(int i=0;i<W;i++){
            int from,to,cost;
            cin>>from>>to>>cost;
            from--;
            to--;
            es[E].from=from;
            es[E].to=to;
            es[E].cost=-cost;
            E++;
        }
        cout<<(find_negative_loop()?"YES":"NO")<<endl;
    }
}
