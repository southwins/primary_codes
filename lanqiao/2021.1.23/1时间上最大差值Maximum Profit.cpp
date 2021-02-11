#include<iostream>
using namespace std;

int main() {
	long a[200000];
	int n;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	long max=-999999999,min=a[0];
	for(int i=1;i<n;i++) {
		if(a[i]-min>max)max=a[i]-min;//每次只跟 已知 最小值比较 
		if(a[i]<min)min=a[i];
	}

	cout<<max<<endl;
	return 0;
}
