#include<bits/stdc++.h>
using namespace std;

long long ans[25]={0,0,1,4,11,26,57,120,247,502,1013,2036,4083,8178,16369,32752,65519,131054,262125,524268,1048555};
long long a[25][25];

int work(int n,int m){
	if(a[n][n-m]!=0){
		return a[n][m]=a[n][n-m];
	}
	long long all=1;
	for(int i=n-m+1;i<=n;i++){
		all*=i;
	}
	for(int i=m;i>0;i--){
		all/=i;
	}
	a[n][m]=all;
//	cout<<n<<" "<<m<<" "<<all<<endl;
	return all;
}

int main(){
//	for(int i=2;i<=20;i++){
//		long long temp=0;
//		
//		for(int j=2;j<=i;j++){
//			temp+=work(i,j);
//		}
//		a[i][0]=temp;
//	}
	
	int k;
	cin>>k;
//	cout<<a[k][0]*2<<endl;
	cout<<ans[k]*2<<endl;
	
	return 0;
} 
