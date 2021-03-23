#include<bits/stdc++.h>
using namespace std;

int a[35][35];//第i次传球到j的可能性 

void work(int n,int m){
	a[0][1]=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int x=j-1,y=j+1;
			if(j==1)x=n;
			if(j==n)y=1;
			a[i][j]=a[i-1][x]+a[i-1][y];
		}
	}
}

int main(){

	int n,m;
	cin>>n>>m;
	work(n,m);
	cout<<a[m][1]<<endl;
	return 0;
}
