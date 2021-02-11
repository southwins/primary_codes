#include<iostream>
#include<algorithm> 
#define INF 0x3f3f3f3f
using namespace std;


int min(int a,int b){
	if(a>b)return b;
	return a;
}

int coins[21],zxs[50001];//硬币种类面值，凑出j元的最小硬币数 



int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>coins[i];
	}
	sort(coins+1,coins+m+1);
	
	for(int i=1;i<=n;i++){
		zxs[i]=INF;
	}
	zxs[0]=0;
	for(int i=1;i<=m;i++){
		for(int j=coins[i];j<=n;j++){
			zxs[j]=min(zxs[j],zxs[j-coins[i]]+1);
			//cout<<j<<" "<<zxs[j]<<endl;
		}
	}
	cout<<zxs[n]<<endl;
	return 0;
} 
