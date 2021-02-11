#include<iostream>
#include<string>
#include<cstdio>
#include<stdlib.h>
#define maxsize 100
#define LL long long
using namespace std;


struct stack{
	LL data[maxsize];
	int top;
}stack1;

bool push(stack&p,LL a){
	if(p.top==maxsize)return false;
	p.data[++p.top]=a;
	return true;
}

bool pop(stack&p,LL &a){
	if(p.top==-1)return false;
	a=p.data[p.top--];
	return true;
}

int main(){
	stack1.top=-1;
	char a[110];
	while(scanf("%s",a)!=EOF){
		if(a[0]=='+'){
			LL x,y;
			pop(stack1,x);pop(stack1,y);
			push(stack1,x+y);
		}
		else if(a[0]=='-'){
			LL x,y;
			pop(stack1,x);pop(stack1,y);
			push(stack1,y-x);
		}
		else if(a[0]=='*'){
			LL x,y;
			pop(stack1,x);pop(stack1,y);
			push(stack1,x*y);
		}
		else push(stack1,atoi(a));//GOOD:
	}
	cout<<stack1.data[stack1.top]<<endl;
	
	return 0;
} 
