#include <iostream>
#include <queue>
#include<string>
using namespace std;

struct proc{
	string name;
	int t,use;
};
 
int main()
{
	int n,time;
	cin>>n>>time;
	queue<proc>q1;
	proc *p=new proc[n];
	for(int i=0;i<n;i++){
		cin>>p[i].name>>p[i].t;
		p[i].use=0;
		q1.push(p[i]);
	}
	int count=0,nowtime=0;
	while(1){
		if(count>=n)break;
		proc temp=q1.front();
		q1.pop();
		if(temp.t>time){
			nowtime+=time;
			temp.t-=time;
			q1.push(temp);
		}
		else if(temp.t!=0) {
			nowtime+=temp.t;
			temp.t=0;
			temp.use=nowtime;
			q1.push(temp);
			count++;
			cout<<temp.name<<" "<<temp.use<<endl;
		}
		
	}
    return 0;
}
