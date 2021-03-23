#include<bits/stdc++.h>
using namespace std;

int n,sum;


int main(){
	cin>>n>>sum;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		a[i]=i+1;
	}
	do{
		vector<int>b=a;
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-i-1;j++){
				b[j]+=b[j+1];
			}
		}
		if(b[0]==sum){
			for(int i=0;i<n;i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
			break;
		}
	}while(next_permutation(a.begin(), a.end()));
	return 0;
}
