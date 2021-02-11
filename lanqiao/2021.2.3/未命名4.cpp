#include<bits/stdc++.h>
using namespace std;

#define maxx 8000000
#define modd 1000000007
#define LL long long

int prime[maxx+5];

void work(){
	for(int i=2;i<=maxx;i++){
		if(prime[i]==0)prime[++prime[0]]=i;
		for(int j=1;j<=prime[0];j++){
			if(i*prime[j]>maxx)break;
			prime[i*prime[j]]=-1;
			if(i%prime[j]==0)break;
		}
	}
}

LL F(int a){
	string all;
	int i=1,aa=a;
	while(a!=1){
		if(a%prime[i]==0){
			string temp; 
			stringstream s;
			s<<prime[i];
			s>>temp;
			all+=temp;
			a/=prime[i];
		}
		else {
			i++;
			//cout<<i<<endl;
		}
	}
	//if(aa%10000==0)cout<<"---------"<<all<<endl;
	LL anum;
	stringstream s;
	s<<all;
	s>>anum;
	return anum;
}

int main(){
	work();
	int n=4000000;
	cin>>n;
	int total=0;
	for(int i=2;i<=n;i++){
		LL temp=F(i);
		temp%=modd;total+=temp;
		total%=modd;
//		if(i%10000==0)cout<<i<<" "<<F(i)<<endl;
//		if(i%10003==0)cout<<i<<" "<<F(i)<<endl;
	}
	cout<<total<<endl;
	return 0;
}
