#include<iostream>
using namespace std;


double p[505],q[505];
double mint[505][505];
double w[505][505];

double zscs(int i,int k,int j){//最少次数
	if(i==j)return w[i][j];
	cout<<i<<" "<<j<<" "<<mint[i][j]<<endl;
	if(j<i){
		return mint[i][j];
	}
	double now=zscs(i,k+1,k)+zscs(k+1,k+1,j)+w[i][j];
	if(k==i-1||now<mint[i][j])mint[i][j]=now;
	return mint[i][j];
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=0;i<=n;i++){
		cin>>q[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=i-1;k<=j;k++){
				if(k!=i-1)w[i][j]+=p[k];
				w[i][j]+=q[k];
			}
		}
		
	}
	cout<<zscs(1,0,n)<<endl;
	return 0;
}
