#include<bits/stdc++.h>
using namespace std;

int a[70],n,all,len;
bool cmp(int a,int b) {
	return a>b;
}
int color[70];
bool dfs(int num,int nowl,int alll) {
	if(alll==all){
		return true;
	}
	if(nowl==len){
		nowl=0;num=1;
	}
	for(int i=num;i<=n;i++){
		if(color[i]||nowl+a[i]>len)continue;
		color[i]=1;
		if(dfs(i,nowl+a[i],alll+a[i]))return true;
		color[i]=0;
		if(nowl+a[i]==len||nowl==0)return false;
		while(a[i+1]==a[i])++i;
	}
	return false;
}

int main() {
	while(cin>>n) {
		if(n==0)break;
		all=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
			all+=a[i];
		}
		sort(a+1,a+n+1,cmp);
		int ans=-1;
		for(len=a[1]; len<=all; len++) {
			
			if(all%len==0) {
				//cout<<len<<endl;
				memset(color,0,sizeof(color));
				if(dfs(1,0,0)) {
					ans=len;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
