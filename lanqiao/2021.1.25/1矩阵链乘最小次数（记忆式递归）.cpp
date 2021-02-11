#include<iostream>
#define INF 0x3f3f3f3f
using namespace std;

int p[210];
int minc[101][101];

int zxcc(int i,int j){//×îÐ¡³Ë´Î 
	if(i==j){
		return minc[i][j];
	}
	if(i<j){
		if(minc[i][j]!=0)return minc[i][j];
		int a=INF;
		for(int k=i;k<j;k++){
			int now=zxcc(i,k)+zxcc(k+1,j)+p[i-1]*p[k]*p[j];
			if(now<a)a=now;
		}
		minc[i][j]=a;
		return minc[i][j];
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<n+1;i++){//
		cin>>p[i-1]>>p[i];
	}
	cout<<zxcc(1,n)<<endl;
	return 0;
} 
