#include<iostream>
#include<vector>
using namespace std;

vector<int>g[100];//�ڽӱ��������ʽ

int shuitong[100];

void bfs(int to,int c){
	shuitong[to]=c;
	c++;
	for(int i=0;i<g[to].size();i++){
	//	cout<<i<<endl;
		if((g[to][i]!=1&&!shuitong[g[to][i]])||shuitong[g[to][i]]>c){
			bfs(g[to][i],c);
		}
	}
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
	bfs(1,0);
	
	for(int i=1;i<=n;i++){
		if(i==1||shuitong[i]!=0){
			cout<<i<<" "<<shuitong[i]<<endl;
		}
		else{
			cout<<i<<" "<<-1<<endl;
		}
	}
	
	return 0;
}
