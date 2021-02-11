#include<iostream>
#include<string>
#include<vector>
using namespace std;

//链接：https://ac.nowcoder.com/acm/contest/9981/C
//来源：牛客网
//
//你拿到了一棵树，请你给每个顶点染成红色或蓝色。
//要求：每个红点周围有且仅有一个红点，每个蓝点周围有且仅有一个蓝点。
//“周围”的定义：某点周围的点指通过邻边直接连接的点。
//所谓树，即没有自环、重边和回路的无向连通图。

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
