#include<iostream>
using namespace std;

struct Bstnode {
	int key;
	Bstnode*parent,*lc,*rc; 
};

class Bst {
	public:
		Bstnode*origin;
		int n;
		Bst() {
			origin=NULL;
			n=0;
		}
		bool insert(Bstnode*p,int k){
			if(p==NULL){
				p=new Bstnode;
				p->key=k;
				p->lc=p->rc=NULL;
			}
			else if(k==p->key){
				return false;
			}
			else if(k<p->key){
				insert(p->lc,k);
			}
			else {
				insert(p->rc,k);
			}
//			Bstnode*p=new Bstnode;
//			p->key=k;
//			p->lc=NULL,p->rc=NULL;
//			
//			Bstnode*now=origin;
//			cout<<endl;
//			while(now!=NULL){
//				cout<<"now"<<now->key<<" ";
//				if(k<now->key){
//					if(now->lc!=NULL)now=now->lc;
//					else{
//						now->lc=p;
//						p->parent=now;
//					}
//					n++;
//					return true;
//				}
//				if(k>now->key){
//					if(now->rc!=NULL)now=now->rc;
//					else {
//						now->rc=p;
//						p->parent=now;
//					}
//					n++;
//					return true;
//				}
//				if(k==now->key)return false;
//			}
//			cout<<endl;
//			origin=p;
//			n++;
//			return true;
		}
		bool find(int k){
			Bstnode*now=origin;
			while(now!=NULL){
				if(k<now->key){
					now=now->lc;
				}
				else if(k>now->key){
					now=now->rc;
				}
				else if(k==now->key)return true;
			}
			return false;
		}
		void xianxu(Bstnode*now){
			cout<<" "<<now->key;
			if(now->lc!=NULL)xianxu(now->lc);
			if(now->rc!=NULL)xianxu(now->rc);
		}
		void zhongxu(Bstnode*now){
			if(now->lc!=NULL)zhongxu(now->lc);
			cout<<" "<<now->key;
			if(now->rc!=NULL)zhongxu(now->rc);
		}
};

int main() {
	int n;
	cin>>n;
	Bst test;
	while(n--){
		char a[20];
		cin>>a;
		switch(a[0]){
			case'i':{
				int k; 
				cin>>k;
				test.insert(test.origin,k);
				cout<<endl<<test.n<<endl;
				break;
			}
			case'f':{
				int k;
				cin>>k;
				if(test.find(k)){
					cout<<"yes"<<endl;
				}
				else cout<<"no"<<endl;
				break;
			}
			case'p':{
				test.zhongxu(test.origin);cout<<endl;
				test.xianxu(test.origin);cout<<endl;
				break;
			}
		}
	}
	return 0;
}
