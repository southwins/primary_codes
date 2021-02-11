#include<iostream>
#include<string>
#include<map>
using namespace std;

string pi,pj;
map<pair<int,int>,int>maxc;


int zdcd(int i,int j){//最大公共长度 
	if(i==0||j==0){
		return maxc[make_pair(i,j)];
	}
	if(pi[i]==pj[j]){
		if(maxc[make_pair(i,j)]!=0)return maxc[make_pair(i,j)];
		maxc[make_pair(i,j)]=zdcd(i-1,j-1)+1;
		return maxc[make_pair(i,j)];
	}
	if(maxc[make_pair(i,j)]!=0)return maxc[make_pair(i,j)];
	int a,b;
	a=zdcd(i-1,j),b=zdcd(i,j-1);
	if(a>b)maxc[make_pair(i,j)]=a;
	else maxc[make_pair(i,j)]=b;
	return maxc[make_pair(i,j)];
}

int main(){
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		maxc.erase(maxc.begin(),maxc.end());
		cin>>pi>>pj;
		pi="0"+pi;
		pj="1"+pj;
		cout<<zdcd(pi.length()-1,pj.length()-1)<<endl;
	}
	return 0;
}
