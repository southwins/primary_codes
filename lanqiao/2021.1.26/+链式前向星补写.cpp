#include<iostream>
using namespace std;

const int maxv=100,maxe=100;

int head[maxv];

struct Edge{
    int next,to,w;//���������һ���ߣ��ñ�ָ��ĵ㣬�ñߵ�Ȩֵ
}edge[maxe];

int cnt=0;
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
for trav(int v){//����v�����б�
    for(int i=head[v];i!=0;i=head[v].next){
        cout<<v<<"to"<<edge[i].to<<"cost"<<edge[i].w;
    }
}

int main(){

    return 0;
}