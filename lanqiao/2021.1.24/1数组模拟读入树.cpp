#include<iostream>
#include<vector>
using namespace std;


struct tnode {
	int id,parent,lchild,rsibling;
	vector<int>childs;
}*tnode1;

bool showchs(tnode&p) {
	int flag=1;
	for(int i=0; i<p.childs.size(); i++) {
		if(flag)cout<<p.childs[i];
		else cout<<", "<<p.childs[i];
		flag=0;
	}
}

int fdepth(tnode*p,int id) {
	if(p[id].parent==-1)return 0;
	return fdepth(p,p[id].parent)+1;
}

int main() {
	int n;
	cin>>n;
	tnode1=new tnode[n];

	for(int i=0; i<n; i++) {
		tnode1[i].parent=-1;
		tnode1[i].lchild=tnode1[i].rsibling=-1;
		tnode1[i].where=0;
	}


	for(int i=0; i<n; i++) {
		int id,chs;
		cin>>id>>chs;

		int ch,rem;
		for(int j=0; j<chs; j++) {
			cin>>ch;
			tnode1[id].childs.push_back(ch);
			tnode1[ch].parent=id;//每个孩子都记住自己的父节点
			if(j==0) {
				tnode1[id].lchild=ch;//第一个孩子挂在父节点的左孩子
			} else {
				tnode1[rem].rsibling=ch;//其他孩子都依次挂在右兄弟上
			}
			rem=ch;
		}
	}

	for(int i=0; i<n; i++) {
		cout<<"node "<<i
		    <<": parent = "<<tnode1[i].parent
		    <<", depth = "<<fdepth(bstnode1,i)
		    <<", ";
		if(tnode1[i].parent==-1) {
			cout<<"root, [";
			showchs(tnode1[i]);
			cout<<"]"<<endl;
		} else if(tnode1[i].lchild==-1) {
			cout<<"leaf, []"<<endl;
		} else {
			cout<<"internal node, [";
			showchs(tnode1[i]);
			cout<<"]"<<endl;
		}
	}

	return 0;
}
