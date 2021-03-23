#include<bits/stdc++.h>
using namespace std;

int w[10005],q[105];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>w[i];
	
	int k=0,ans=0;
	
	for(int i=0;i<m;i++)q[i]=w[k++];
	
	while(k<n){
		int min_=INT_MAX;
		for(int i=0;i<m;i++){
			if(q[i]<min_){
				min_=q[i];
			}
		}
		
		ans+=min_;
		
		for(int i=0;i<m;i++){
			q[i]-=min_;
			if(q[i]==0)q[i]=w[k++];
		}
		
	}
	
	int max_=INT_MIN;
	for(int i=0;i<m;i++){
		if(q[i]>max_){
			max_=q[i];
		}
	}
	ans+=max_;
	cout<<ans<<endl;
	
	return 0;
}

