#include<bits/stdc++.h>
using namespace std;


struct unit{
	int w[105]={0};
	int id;
	int cant=0;
}a[1005];

int n,m,k;

bool cmp(unit aa,unit bb){
	for(int i=0;i<m;i++){
		if(aa.w[i]!=bb.w[i])
			return aa.w[i]>bb.w[i];
	}
}

int main(){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		a[i].id=i+1;
		for(int j=0;j<m;j++){
			cin>>a[i].w[j];
			if(a[i].w[j]<85){
				a[i].cant=1;
			}
		}
	}

	sort(a,a+n,cmp);

	for(int i=0,kk=0;i<n&&kk<k;i++){
		if(a[i].cant==0){
			cout<<a[i].id<<" ";
			kk++;
		}
	}

	return 0;
} 
