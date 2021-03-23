#include<iostream>
using namespace std;

long long o[45]={0,1,2};
long long a[45]={0,3,8};

int main(){
	int n;
	for(int i=3;i<41;i++){
		a[i]=a[i-1]*3-o[i-1];
		o[i]=a[i-1]-o[i-1];
	}
	while(cin>>n){
		cout<<a[n]<<endl;
	}
	 
	return 0;
}
