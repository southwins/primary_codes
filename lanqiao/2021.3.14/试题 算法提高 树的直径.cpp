#include<bits/stdc++.h>
using namespace std;

int n;
struct edge{
	int to,w;
};
vector<edge>g[100000];
int vis[100000];

int deepestid,deep;
void dfs(int id,int ceng){
	vis[id]=1;
	if(ceng>deep){
		deep=ceng;
		deepestid=id;
	}
	for(int i=0;i<g[id].size();i++){
		if(vis[g[id][i].to]==1)continue;
		//cout<<g[id][i].to<<endl;
		dfs(g[id][i].to,ceng+1);
	}
}

int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int id,to,w;
		cin>>id>>to>>w;
		edge temp;
		temp.to=to,temp.w=w;
		g[id].push_back(temp);
		temp.to=id;
		g[to].push_back(temp);
	}
	dfs(1,0);
//	cout<<deepestid<<" "<<deep<<endl;
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	dfs(deepestid,0);
	cout<<deep<<endl;
	
	return 0;
} 
