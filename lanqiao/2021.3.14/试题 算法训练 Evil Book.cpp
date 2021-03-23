#include<bits/stdc++.h>
using namespace std;


int t,n,x;
struct chief{
	float c,m;
}p[12]; 

bool cmp(chief a,chief b){
	return a.c<b.c;
}

int main(){
	cin>>t;
	while(t--){
		cin>>n>>x;
		int all=0;
		for(int i=0;i<n;i++){
			cin>>p[i].c>>p[i].m;
			all+=p[i].m;
		}
		if(all<666){
			cout<<"impossible"<<endl;
			return 0;
		}
		sort(p,p+n,cmp);
		float cost=0,get=0;
		int i=0;
		while(i<n&&get<666){
			if(get>=x&&all-(p[i].m/3.0)*2.0>666){
				p[i].c/=3.0;
				p[i].m/=3.0;
				get-=x;
			}
			while(get>=x&&(p[i].m/3.0)>=666{
				p[i].c/=3.0;
				p[i].m/=3.0;
				get-=x;
				cout<<"____"<<p[i].c<<" "<<p[i].m<<endl;
			}
			cost+=p[i].c;
			get+=p[i].m;
			cout<<"===="<<get<<endl;
			i++;
		}
		if(get>666)printf("%.0f\n",cost);
		else cout<<"impossible"<<endl;
		
	}
	return 0;
}
