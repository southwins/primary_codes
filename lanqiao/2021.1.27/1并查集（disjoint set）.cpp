#include<iostream>
using namespace std;

struct graph {
	int fa,high;
} g[10000];

int findroot(int x) {
	//cout<<x<<"___fa:"<<g[x].fa<<endl;
	if(g[x].fa!=x) {
		g[x].fa=findroot(g[x].fa);
	}
	return g[x].fa;
}
void unite(int a,int b) {
	int x=findroot(a),y=findroot(b);
	if(g[x].high>g[y].high) {
		g[y].fa=g[x].fa;
	} else {
		g[x].fa=g[y].fa;
		if(g[x].high==g[y].high) {
			g[y].high++;
		}
	}
}
void same(int a,int b) {
	int af=findroot(a),bf=findroot(b);
	if(af==bf)cout<<1<<endl;
	else cout<<0<<endl;
}

int main() {
	int n,q;
	cin>>n>>q;
	for(int i=0; i<n; i++) {
		g[i].fa=i;
		g[i].high=0;
	}
	for(int i=0; i<q; i++) {
		int com,a,b;
		cin>>com>>a>>b;
		if(com==0) {
			unite(a,b);
		} else same(a,b);
	}
	return 0;
}
