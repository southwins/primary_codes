#include<iostream>
using namespace std;

int num[111]={0};
void yueshu(int n){
	for(int i=1;i<=n;i++){
		if(n%i==0&&num[i]==0)num[i]=1;
	}
}
//pailiezuhe wangl
int main(){
	double total=1;
	for(int i=1;i<=99;i++){
		total*=i;
	}
	cout<<total<<endl;
	return 0;
} 
 
