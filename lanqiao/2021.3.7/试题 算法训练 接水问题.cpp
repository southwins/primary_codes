#include<bits/stdc++.h>
using namespace std;


int w[10000],flag[10000];//flag用来判断是否i在已接水队列中

struct cmp {
	bool operator()(int a,int b) {
		return w[a]>w[b];//按w[i]升序排序
	}
};

priority_queue<int,vector<int>,cmp>q;

int main() {
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>w[i];
	}

	int ans=0;
	int i,s=0;
	for(i=0; i<m&&i<n; i++) {
//		cout<<w[i]<<endl;
		q.push(i);
		flag[i]=1;
	}

	while(!q.empty()) {

		int now=q.top();
		q.pop();


		ans+=w[now];
		int last=w[now];
//		cout<<"++++"<<w[now]<<"==="<<ans<<endl;

		int cnt=0;
		for(int j=0; cnt<m&&j<n; j++) {
			if(flag[j]==1) {
				w[j]-=last;
				cnt++;
//				cout<<"_____"<<j<<"==="<<w[j]<<endl;
			}

		}
		flag[now]=0;


		while(i<n&&q.size()<m) {
//			cout<<w[i]<<endl;
			q.push(i);
			flag[i++]=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
