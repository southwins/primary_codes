#include<iostream>
#include<cmath>
using namespace std;

int howmany(int len) {
	if(len==2)return 1;
	int c=1;
	for(int i=len; i>2; i--) {
		c*=i;
		c%=(1000000007);
	}
	int k=1;
	for(int i=len-2; i>0; i--) {
		k*=26;
		k%=(1000000007);
	}
	int all;
	all=(k*c)%(1000000007)-(len-1)%(1000000007)+howmany(len-1)%(1000000007);
	return all%(1000000007); 
}

int main() {
	int n;
	cin>>n;
	cout<<howmany(n)<<endl;
	return 0;
}
