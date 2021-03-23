#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll a[25];
int n,t,c;


int main() {
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	cin>>t;
	for(int i=1;i<(1<<n);i++){
		ll sum=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j))sum+=a[j];
		}
		if(sum==t){
			for(int j=0;j<n;j++){
				if(i&(1<<j))cout<<a[j]<<" ";
			}
			cout<<endl;
			c++;
		}
	}
	cout<<c<<endl;
	return 0;
}
