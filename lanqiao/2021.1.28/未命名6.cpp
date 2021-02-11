#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int n,remx[1000000],remy[1000000];
string a,x="Alice",y="Bob";

bool isok(char aa){
	if(aa>'a'&&aa<'z')return false;
	if(aa>'A'&&aa<'Z')return false;
	return true;
}

int main(){
	cin>>n;
	char temp;
	getchar();
	while(1){
		cin>>noskipws>>temp;
		if(temp=='\n')break;
		a+=temp;
	}
	//cout<<a<<endl;
	int kx=0,ky=0,count=0;
	for(int i=0;i<a.size();i++){
		//cout<<a.substr(i,5)<<endl;
		if(a.substr(i,5)==x){
			//cout<<i<<endl;
			if(i==0&&!isok(a[i+5]))continue;
			if(i!=0&&(!isok(a[i-1])&&!isok(a[i+5])))continue;
			remx[kx++]=i;
			//cout<<i<<endl;
		}
		else if(a.substr(i,3)==y){
			//cout<<i<<endl;
			if(i==0&&!isok(a[i+5]))continue;
			if(i!=0&&(!isok(a[i-1])&&!isok(a[i+5])))continue;
			remy[ky++]=i;
			//cout<<i<<endl;
		}
	}
	
	int t1,t2;
	for(int i=0;i<kx;i++){
		t1=remx[i];
		for(int j=0;j<ky;j++){
			t2=remy[j];
			if(abs(t1-t2)<=n)count++;
			else break;
		}
	}
	cout<<count<<endl;
	return 0;
}
