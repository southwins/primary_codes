#include<iostream>
#include<string>
using namespace std;

struct S{
		string name;
		int av,banji,lws;
		char isgb,isxb;
		int jiangxuejin=0;
};

int main(){
	int n;
	cin>>n;
	S *p=new S[n];
	int maxi=0,max=0,total=0;
	for(int i=0;i<n;i++){
		cin>>p[i].name>>p[i].av>>p[i].banji
		>>p[i].isgb>>p[i].isxb>>p[i].lws;
		if(p[i].av>80&&p[i].lws>=1){
			p[i].jiangxuejin+=8000;
		}
		if(p[i].av>85&&p[i].banji>80){
			p[i].jiangxuejin+=4000;
		}
		if(p[i].av>90){
			p[i].jiangxuejin+=2000;
		}
		if(p[i].av>85&&p[i].isxb=='Y'){
			p[i].jiangxuejin+=1000;
		}
		if(p[i].banji>80&&p[i].isgb=='Y'){
			p[i].jiangxuejin+=850;
		}
		if(p[i].jiangxuejin>max){
			max=p[i].jiangxuejin;
			maxi=i;
		}
		total+=p[i].jiangxuejin;
	}
	cout<<p[maxi].name<<endl;
	cout<<max<<endl;
	cout<<total<<endl;
	return 0;
}
