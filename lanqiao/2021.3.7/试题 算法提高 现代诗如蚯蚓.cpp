#include<bits/stdc++.h>
using namespace std;

int main(){
	string a;
	cin>>a;
	int len=a.length();
	int ans=-1;
	for(int i=1;i<len/2;i++){
		if(len%i!=0)continue; 
		int flag=0;
		string t1=a.substr(0,i),t2;
		for(int j=i;j<len;j+=i){//Ãî 
			t2=a.substr(j,i);
//			cout<<t1<<" "<<t2<<endl;
			if(t1!=t2){
				flag=1;
				break;
			}
		}
		if(flag==0&&i>ans){
			cout<<len/i<<endl;
			return 0;//ÌáÇ°ÖÕÖ¹ 
		}
	}
	cout<<1<<endl;
	
	return 0;
}
