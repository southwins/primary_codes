#include<iostream>
using namespace std;

const int maxv=100,maxe=100;

int head[maxv];

struct Edge{
    int next,to,w;//共顶点的下一条边，该边指向的点，该边的权值
}edge[maxe];

int cnt=0;
void init(){
    for(int i=0;i<maxv;i++){
        head[i]=-1;
    }
}
void add(int dd,int xd,int w){//分别代表所加边的顶点，向点和权值
    edge[cnt].w=w;
    edge[cnt].to=xd;
    edge[cnt].next=head[dd];//关键：新加边的【共顶点下一条边】是原顶点第一条边
    head[dd]=cnt++;//原顶点第一条边切换为新加边
}
void adds(int dd,int xd,int w){//无向图双向加边
    add(dd,xd,w);
    add(xd,dd,w);
}
for trav(int v){//遍历v的所有边
    for(int i=head[v];i!=-1;i=edge[i].next){
        cout<<v<<"to"<<edge[i].to<<"cost"<<edge[i].w;
    }
}

int main(){

    return 0;
}