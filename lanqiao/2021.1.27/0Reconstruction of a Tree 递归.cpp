#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

vector<int>pre,in,post;
int pos;

void rec(int l,int r){
	if(l>=r)return;
	int root=pre[pos++];
	int m=(int)distance(in.begin(),find(in.begin(),in.end(),root));
	rec(l,m);rec(m+1,r);
	post.push_back(root);
	cout<<root;
	if(root!=pre[0])cout<<" ";
} 

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int v;
		cin>>v;
		pre.push_back(v);
	}
	for(int i=0;i<n;i++){
		int v;
		cin>>v;
		in.push_back(v);
	}
	rec(0,n);
	cout<<endl;
	return 0;
}
