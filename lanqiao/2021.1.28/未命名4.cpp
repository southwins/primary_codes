#include<iostream>
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int a[100000];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int min=INF,maxa=0,mina=INF;
	for(int i=0;i<n;i++){
		if(maxa<a[i])maxa=a[i];
		if(mina>a[i])mina=a[i];
		int temp=a[i+1]-a[i];
		if(temp<min&&temp>=0)min=temp;
	}
	//cout<<maxa<<mina<<min<<endl;
	if(min!=0)cout<<(maxa-mina)/min+1<<endl;
	else cout<<n<<endl;
	return 0;
}
