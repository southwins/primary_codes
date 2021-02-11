#include<iostream>
#include<cstring>
using namespace std;

char deng[1000003];

int main(){
	memset(deng,0,1000003);
	int n,num,max=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		if(num>max)max=num;
		if(deng[num]==0)deng[num]=1;
		else deng[num]=0;
	}
	for(int i=0;i<=max;i++){
		if(deng[i]==1){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
