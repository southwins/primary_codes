#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

int color[100000];
struct node{
	vector<int>arcs; 
};

void dfs(node*p,int v,int c){
	color[v]=c;
	for(int i=0;i<p[v].arcs.size();i++){
		int to=p[v].arcs[i];
		if(!color[to]){
			dfs(p,to,c);
		}
	}
}

//bool pa(node*p,char*tong,int id,int who){
//	tong[id]=1;
//	if(id==who)return true;
//	bool flag=false;
//	for(int i=0;i<p[id].arcs.size();i++){
//		if(tong[p[id].arcs[i]]==0){
//			if(pa(p,tong,p[id].arcs[i],who))flag=true;
//		}
//	}
//	return flag;
//}

int main(){
	int n,m;
	cin>>n>>m;
	node*p=new node[n];
	for(int i=0;i<m;i++){
		int id,who;
		cin>>id>>who;
		p[id].arcs.push_back(who);
		p[who].arcs.push_back(id);
	}
	int c=1;
	for(int i=0;i<n;i++){
		if(!color[i]){
			dfs(p,i,c);
			c++;
		}
	}
	
	
	int q;
	cin>>q;
//	char*tong=new char[n+1];
//	for(int i=0;i<q;i++){
//		memset(tong,0,n+1);
//		int id,who;
//		cin>>id>>who;
//		if(pa(p,tong,id,who))cout<<"yes"<<endl;
//		else cout<<"no"<<endl;
//	}

	for(int i=0;i<q;i++){
		int id,who;
		cin>>id>>who;
		if(color[id]==color[who]){
			cout<<"yes"<<endl;
		}
		else cout<<"no"<<endl;
	}
	
	return 0;
}

