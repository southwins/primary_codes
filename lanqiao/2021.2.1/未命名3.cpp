#include<iostream>
#include<string>
#include<vector>
using namespace std;

//���ӣ�https://ac.nowcoder.com/acm/contest/9981/C
//��Դ��ţ����
//
//���õ���һ�����������ÿ������Ⱦ�ɺ�ɫ����ɫ��
//Ҫ��ÿ�������Χ���ҽ���һ����㣬ÿ��������Χ���ҽ���һ�����㡣
//����Χ���Ķ��壺ĳ����Χ�ĵ�ָͨ���ڱ�ֱ�����ӵĵ㡣
//��ν������û���Ի����رߺͻ�·��������ͨͼ��

struct node{
	vector<int>arcs;
	int n=0,pair=0;
	int c=0;
};

int fpair(node*t,int n){
	int pa=0;
	for(int i=1;i<=n;i++){
		if(t[i].pair!=0)continue;
		if(t[i].n==1){
			int j=t[i].arcs[0];
			if(t[j].pair!=0)continue; 
			t[i].pair=j;t[j].pair=i;pa++;
		}
	}
	for(int i=1;i<=n;i++){
		if(t[i].pair!=0)continue;
		for(int j=0;j<t[i].n;j++){
			int k=t[i].arcs[j];
			if(t[k].pair==0){
				t[i].pair=k;t[k].pair=i;pa++;
				break;
			}
		}
	}
	int gu=n-(pa)*2;
	return gu;
}

void color(node*t,int i,int c){
	if(t[i].c!=0);
	else {
		t[t[i].pair].c=t[i].c=c;
		if(t[i].n>1)for(int j=0;j<t[i].n;j++){
			if(j!=t[i].pair)color(t,t[i].arcs[j],c+1);
		}
		if(t[t[i].pair].n>1)for(int j=0;j<t[t[i].pair].n;j++){
			if(j!=t[t[i].pair].pair)color(t,t[t[i].pair].arcs[j],c+1);
		}
	}
}

int main(){
	int n;
	cin>>n;
	node*t=new node[n+1];
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		t[u].arcs.push_back(v);
		t[v].arcs.push_back(u);
		t[u].n++,t[v].n++;
		
	}
	if(fpair(t,n)>0){
		cout<<-1<<endl;
		return 0;
	}
	color(t,1,1);
	for(int i=1;i<=n;i++){
		if(t[i].c&1)cout<<'R';
		else cout<<'B';
	}
	cout<<endl;
	return 0;
}
