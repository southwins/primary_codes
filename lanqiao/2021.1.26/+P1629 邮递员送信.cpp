#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxe=100005;
const int maxv=1005;

struct Edge{
	int next,to,w;
}edge[maxe];
int head[maxv],vis[maxv],dis[maxv],cnt;

void add(int dd,int xd,int w){
	edge[cnt].w=w;
	edge[cnt].to=xd;
	edge[cnt].next=head[dd];
	head[dd]=cnt++;
}
void init(){
	for(int i=0;i<=maxv;i++){
		head[i]=-1;
	}
}

struct cmp{
	bool operator()(int a,int b){//°´disÉýÐò 
		return dis[a]>dis[b];
	}
};
priority_queue<int,vector<int>,cmp>q;
void dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	q.push(s);
	while(!q.empty()){
		int now=q.top();
		q.pop();
		if(vis[now])continue;
		vis[now]=1;
		for(int i=head[now];i!=-1;i=edge[i].next){
			int go=edge[i].to,w=edge[i].w;
			if(!vis[go]&&dis[now]+w<dis[go]){
				dis[go]=dis[now]+w;
				if(!vis[go]){
					q.push(go);
				}
			}
		}
	}
}

int main(){
	init();
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v+n,u+n,w);
	}
	long long ans=0;
	dijkstra(1); 
	for(int i=1;i<=n;i++)ans+=dis[i];
	dijkstra(1+n);
	for(int i=1+n;i<=n<<1;i++)ans+=dis[i];
	cout<<ans<<endl;
	return 0;
}