#include<iostream>
#include<vector>
using namespace std;

vector<int>g[100];

int start[100],finish[100];
int time_=1;

void dfs(int v){
	start[v]=time_++;
	for(int i=0;i<g[v].size();i++){
		int to=g[v][i];
		if(!start[to]){
			dfs(to);
		}
	}
	finish[v]=time_++;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		for(int j=0;j<b;j++){
			int c;
			cin>>c;
			g[a].push_back(c);
		}
	}
	
	for(int i=1;i<=n;i++){
		if(!start[i]){
			dfs(i);
		} 
	} 
	for(int i=1;i<=n;i++){
		cout<<i<<" "<<start[i]<<" "<<finish[i]<<endl;
	}
	return 0;
}
