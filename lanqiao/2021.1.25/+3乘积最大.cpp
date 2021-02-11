#include<iostream>
#include<cmath>
#include<algorithm>
#define LL long long
using namespace std;

bool cmp(LL a,LL b) {
	return a>b;
}

LL fmax(LL*p,int k,int n,int count) {
	if(k==1) {
		return p[0];
	}
	if(k<=n-count) {
		LL total=1;
		int is0=0;
		for(int i=0; i<k; i++) {
			if(p[i]!=0)total*=p[i];
			else is0=1;
		}
		if(count<2) {
			if(is0) return 0;
			return total;
		} else {
			for(int c=2; n-count-c>=0&&n-count+c<n; c+=2) {
				LL a=p[n-count-c]*p[n-count-c+1],b=p[n-count+c-2]*p[n-count+c-1];
				if(b>a) {
					if(a!=0)total/=a;
					else total/=p[n-count-c];
					total*=b;
				}
				if(b<a)break;
			}
			return total;
		}
	} else {
		if(count<2) {
			LL total=1;
			for(int i=n-count,j=0; j<k; i--,j++) {
				total*=p[i];
			}
			return total;
		}
		else if((n-count)!=0&&(k-(n-count))&1) { //正数全选后剩下奇数个负数
			LL total=1;
			for(int i=0; i<k-1; i++) {
				total*=p[i];
			}
			total*=p[n-1]*p[n-2];
			return total;
		}
		
		else {
			LL total=1;
			for(int i=0; i<k; i++) {
				total*=p[i];
			}
			return total;
		}
	}
}

int main() {
	int n,k;
	cin>>n>>k;
	LL*p=new LL[n];
	int count=0;
	for(int i=0; i<n; i++) {
		cin>>p[i];
		if(p[i]>=0)p[i]%=1000000009;
		else {
			p[i]=-((-p[i])%1000000009);
			count++;
		}
	}
	sort(p,p+n,cmp);
	LL temp=fmax(p,k,n,count);
	if(temp<0)temp=-((-temp)%1000000009);
	cout<<temp<<endl;
	return 0;
}
