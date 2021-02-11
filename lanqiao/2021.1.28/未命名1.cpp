#include<iostream>
#include<queue>
#define LL long long
using namespace std;

LL a[4];

int main(){
	queue<LL>a;
	a.push(1);
	a.push(1);
	a.push(1);
	for(int i=4;i<=20190324;i++){
		LL x=a.front()%10000;a.pop();
		LL y=a.front()%10000;a.pop();
		LL z=a.front()%10000;a.pop();//
		
		LL temp=x%10000+y%10000+z%10000;
		temp%=10000;
		a.push(y);
		a.push(z);
		a.push(temp);
		if(i==20190324)cout<<temp<<endl;
	}
	
	return 0;
}
