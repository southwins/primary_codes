#include<bits/stdc++.h>
using namespace std;

long long a[1005];

int main(){
	int k,n;
	cin>>k>>n;
	a[0]=1;
	
	int i=1;
	int now=k;
	while(i<n){
		int rem=i;
		a[i++]=now;
		for(int j=0;j<rem&&i<n;j++)a[i++]=now+a[j];//i小于n重要 
		now*=k;
	}
	
	cout<<a[n-1]<<endl;
	return 0;
}
