#include<iostream>
#define LL long long

using namespace std;

LL quick_power(LL a,LL b,LL mod){
	LL A=1,T=a%mod;
	while(b){
		if(b&1){
			A=(A*T)%mod;
		}
		T=(T*T)%mod;
		b>>=1;
	}
	return A;
}


int main(){
	LL m,n;
	cin>>m>>n;
	cout<<quick_power(m,n,1000000007)<<endl;
	return 0;
} 
