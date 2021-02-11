#include<iostream>
#include<cstring>
using namespace std;

struct DNode{
	int data;
	DNode *prior,*next;
}*DLinkList,*end;
void show(DNode&);


bool insert(DNode&p){
	int a;
	cin>>a;
	DNode*newone=new DNode;
	newone->data=a;
	newone->prior=&p;
	newone->next=p.next;
	if(p.next!=NULL)p.next->prior=newone;
	p.next=newone;
	//if(newone->next!=NULL)cout<<newone->next->prior<<endl;
	//show(p);
	return true;
}

bool deletedl(DNode&p){
	int a;
	cin>>a;
	DNode *now=&p;
	while(now=now->next){
		if(now->data==a){
			if(now->prior!=NULL)now->prior->next=now->next;
			if(now->next!=NULL)now->next->prior=now->prior;
			delete now;
			//show(p);
			return true;
		}
	}
	return false;
}

bool deletedlf(DNode&p){
	DNode*old=p.next;
	if(old->next==NULL)return false;
	p.next=old->next;
	old->next->prior=&p;
	delete old;
	//show(p);
	return true; 
}

bool deletedll(DNode&p){
	DNode *old=p.prior;
	if(old->prior==NULL)return false;//一定要防范非法操作 
	old->prior->next=&p;
	p.prior= old->prior;
	delete old;
	//show(p);
	return true;
}
void show(DNode&p){
	DNode*now=p.next;
	int flag=0;
	while(now->next!=NULL){
		if(flag){
			cout<<" ";
		}
		flag=1;
		cout<<now->data;
		now=now->next;
	}
	cout<<endl;
}

int main(){
	DLinkList=new DNode;
	end=new DNode;
	end->data=0;
	end->next=NULL; 
	end->prior=DLinkList;
	DLinkList->data=0;
	DLinkList->next=end; 
	DLinkList->prior=NULL;
	int n;
	cin>>n;
	char command[30];
	memset(command,0,30);
	while(n--){
		cin>>command;
		if(command[0]=='i'){
			insert(*DLinkList);
		}
		else if(command[6]=='F'){
			deletedlf(*DLinkList);
		}
		else if(command[6]=='L'){
			deletedll(*end);
		}
		else if(command[0]=='d'){
			deletedl(*DLinkList);
		}
	}
	show(*DLinkList);
	return 0;
} 
