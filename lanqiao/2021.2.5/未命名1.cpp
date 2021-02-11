#include<bits/stdc++.h>
using namespace std;

int he(int n){
	int total=0;
	do{
		total+=n-(n/10)*10;
	}while(n/=10);
	return total;
}

int main(){
	int n;
	cin>>n;
	int weihe=he(n);
	for(int i=n+1;i<100000;i++){
		if(he(i)==weihe){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
} 
