#include<iostream>
#include<cstring>
using namespace std;

char tran(char a,int n){
	int wei=a-'a'+n;
	int flag=0;
	if(wei>'z'-'a')flag=1;
	while(wei>'z'-'a'){
		wei-='z'-'a';
	}
	if(flag)wei--;
	return (char)(wei+'a');
}

int main(){
	int n;
	cin>>n;
	char yuanwen[51];
	memset(yuanwen,0,51);
	cin>>yuanwen;
	for(int i=0;yuanwen[i]!=0;i++){
		yuanwen[i]=tran(yuanwen[i],n);
	}
	cout<<yuanwen<<endl;
	return 0;
}
 
