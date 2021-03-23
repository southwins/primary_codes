#include<iostream>
using namespace std;

long long a[55]={0,1,2};

int main(){
	int n;
	for(int i=3;i<51;i++){
		a[i]=a[i-1]+a[i-2];
	}
	while(cin>>n){
		cout<<a[n]<<endl;
	}
} 
