#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Btnode {
	int parent,lc,rc,sibling;
}*b1;

int fdepth(Btnode*p,int id) {
	if(p[id].parent==-1)return 0;
	return fdepth(p,p[id].parent)+1;
}
int fheight(Btnode*p,int id) {
	if(p[id].lc==-1&&p[id].rc==-1)return 0;
	int fc1=0,fc2=0;
	if(p[id].lc!=-1)fc1=fheight(p,p[id].lc);
	if(p[id].rc!=-1)fc2=fheight(p,p[id].rc);
	if(fc2>fc1)fc1=fc2;

	return fc1+1;
}

void xianxu(Btnode*p,int root){
	cout<<" "<<root;
	if(p[root].lc!=-1)xianxu(p,p[root].lc);
	if(p[root].rc!=-1)xianxu(p,p[root].rc);
}
void zhongxu(Btnode*p,int root){
	if(p[root].lc!=-1)zhongxu(p,p[root].lc);
	cout<<" "<<root;
	if(p[root].rc!=-1)zhongxu(p,p[root].rc);
}
void houxu(Btnode*p,int root){
	if(p[root].lc!=-1)houxu(p,p[root].lc);
	if(p[root].rc!=-1)houxu(p,p[root].rc);
	cout<<" "<<root;
}

void cengci(Btnode*p,int root,int n){
	int*temp=new int[n];
	int in=0,out=0;//其实是利用数组模拟队列功能

	temp[in++]=root;

	while(in>out){
		int now=temp[out];
		if(now!=-1){
			cout<<" "<<now;
			if(p[now].lc!=-1)temp[in++]=p[now].lc;
			if(p[now].rc!=-1)temp[in++]=p[now].rc;
		}
		out++;
	}
	cout<<endl<<in<<" "<<out<<endl;
}

int main() {
	int n;
	cin>>n;
	b1=new Btnode[n];
	for(int i=0; i<n; i++) {
		b1[i].parent=-1;
		b1[i].sibling=-1;
	}

	for(int i=0; i<n; i++) {
		int id,lc,rc;
		cin>>id>>lc>>rc;
		b1[id].lc=lc;
		b1[id].rc=rc;
		if(lc!=-1) {
			b1[lc].parent=id;
			b1[lc].sibling=rc;
		}
		if(rc!=-1){
			b1[rc].parent=id;
			b1[rc].sibling=lc;
		}
	}
	int root=-1; 
	for(int i=0;i<n;i++){
		if(b1[i].parent==-1){
			root=i;
		}
	}
	cout<<"Preorder"<<endl;
	xianxu(b1,root);cout<<endl;
	cout<<"Inorder"<<endl;
	zhongxu(b1,root);cout<<endl;
	cout<<"Postorder"<<endl;
	houxu(b1,root);cout<<endl;
	cout<<"Levelorder"<<endl;
	cengci(b1,root,n);cout<<endl;
	return 0;
}
