#include<iostream>
#include<vector>

using namespace std;

struct node{
	int first,second;
};

vector<node>g[100];

int color[100],weight,v[100];

void prim(int from){
	color[from]=1;
	cout<<"from"<<from;
	int mini=0,min=0x3f3f3f3f;
	for(int i=0;i<g[from].size();i++){
		if(color[g[from][i].first]==0&&g[from][i].second<min){
//			cout<<"to"<<g[from][i].first<<endl;
			min=g[from][i].second;
			mini=i;
		}
		v[g[from][i].first]=from;
	}
	if(color[g[from][mini].first]==0){
		weight+=min;
		cout<<"to"<<g[from][mini].first<<endl;
		cout<<endl<<weight<<endl;
		prim(g[from][mini].first);
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int len;
			cin>>len;
			if(len!=-1&&i<j){//无向图特点 
				node a,b;
				a.first=j,b.first=i;
				a.second=b.second=len; 
				g[i].push_back(a);
				g[j].push_back(b);
			}
		}
	}
	prim(1);
	for(int i=1;i<=n;i++){
		if(!color[i]){
			cout<<"lose"<<i<<" "<<v[i]<<endl;
			prim(v[i]);
		}
	}
	
	cout<<weight<<endl;
	
	return 0;
}
