#include<iostream>
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
	for(int i=0; i<n; i++) {
		int depth=fdepth(b1,i),height=fheight(b1,i),degree;
		if(b1[i].lc==-1&&b1[i].rc==-1) {
			degree=0;
		} else if(b1[i].lc!=-1&&b1[i].rc!=-1){
			degree=2;
		} else degree=1; 
		cout<<"node "<<i
		    <<": parent = "<<b1[i].parent
		    <<", sibling = "<<b1[i].sibling
		    <<", degree = "<<degree
		    <<", depth = "<<depth
		    <<", height = "<<height
		    <<", ";
		if(b1[i].parent==-1)cout<<"root";
		else if(degree==0)cout<<"leaf";
		else cout<<"internal node";
		cout<<endl;
	}




	return 0;
}
