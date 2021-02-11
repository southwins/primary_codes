#include<iostream>
#include<cstring>
using namespace std;



int main(){
	int n;
	cin>>n;
	int**g=new int*[n+2];
	for(int i=0;i<n+2;i++){
		g[i]=new int[n+2]; 
	}
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<=n+1;j++){
			g[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		for(int j=1;j<=b;j++){
			int c;
			cin>>c;
			g[a][c]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j!=1)cout<<" ";
			cout<<g[i][j];
		}
		cout<<endl;
	}
	return 0;
} 


//Graph
//There are two standard ways to represent a graph 
//G
//=
//(
//V
//,
//E
//)
//, where 
//V
// is a set of vertices and 
//E
// is a set of edges; Adjacency list representation and Adjacency matrix representation.
