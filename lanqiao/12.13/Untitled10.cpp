#include<iostream>
using namespace std;

int gcd(int a,int b){
	int temp;
	while(b){
		temp=a;
		a=b;
		b=temp%b;
	}
	return a;
}

int a[50000];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long total=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(j>i)total+=(a[i]*a[j]/gcd(a[i],a[j]))*2;
			else total+=a[i]*a[j]/gcd(a[i],a[j]);
		}
	}
	cout<<total<<endl;
	
	return 0;
}
