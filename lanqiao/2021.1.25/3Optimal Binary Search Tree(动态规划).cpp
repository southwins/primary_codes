#include<iostream>
using namespace std;


int p[505],q[505];
int mint[505][505];
int w[505][505];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<=n;i++){
		if(i!=0)cin>>p[i];
		cin>>q[i];
	}
	for(int i=1;i<=n;i++){
		mint[i][i-1]=0;
	}
	for(int 1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=i-1;k<=j;k++){
				if(k!=i-1)w[i][j]+=p[k];
				w[i][j]+=q[k];
			}
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int zxt;
			for(int k=i;k<=j;k++){
				int nowt=mint[i][k-1]+mint[k+1][j]+w[i][j];
				if(k==i)zxt=nowt;
				else zxt=
			}
			
		}
	}
	return 0;
}
