#include<iostream>
using namespace std;

const int maxv=100,maxe=100;

int head[maxv];

struct Edge{
    int next,to,w;//���������һ���ߣ��ñ�ָ��ĵ㣬�ñߵ�Ȩֵ
}edge[maxe];

int cnt=0;
void init(){
    for(int i=0;i<maxv;i++){
        head[i]=-1;
    }
}
void add(int dd,int xd,int w){//�ֱ�������ӱߵĶ��㣬����Ȩֵ
    edge[cnt].w=w;
    edge[cnt].to=xd;
    edge[cnt].next=head[dd];//�ؼ����¼ӱߵġ���������һ���ߡ���ԭ�����һ����
    head[dd]=cnt++;//ԭ�����һ�����л�Ϊ�¼ӱ�
}
void adds(int dd,int xd,int w){//����ͼ˫��ӱ�
    add(dd,xd,w);
    add(xd,dd,w);
}
void trav(int v){//����v�����б�
    for(int i=head[v];i!=-1;i=edge[i].next){
        cout<<v<<"to"<<edge[i].to<<"cost"<<edge[i].w;
    }
}

int main(){

    return 0;
}