#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
#include<string>

using namespace std;

#define row 3
#define maxx 9

struct puzzle{
	int f[maxx],space;
	string path;
	bool operator<(const puzzle&p)const{
		for(int i=0;i<maxx;i++){
			if(f[i]!=p.f[i]){
				return f[i]>p.f[i];//
			}
		}
		return false;
	}
	
};

bool isans(puzzle&p){
	for(int i=0;i<maxx;i++){
		if(p.f[i]!=i+1&&i!=8)return false;
	}
	return true;
}

int dirx[4]={-1,1,0,0},diry[4]={0,0,-1,1};
string dir="udlr";//上下左右 

string bfs(puzzle&p){
	queue<puzzle>waiting;
	map<puzzle,bool>color;
	
	p.path="";
	waiting.push(p);
	color[p]==true;
	
	puzzle temp1,temp2;
	
	while(!waiting.empty()){
		temp1=waiting.front();waiting.pop();
		if(isans(temp1)){
			return temp1.path;
		}
		int x=temp1.space/row,y=temp1.space%row;//空格位置 
		for(int i=0;i<4;i++){//四个方向 
			int xx=x+dirx[i],yy=y+diry[i];
			if(xx<0||yy<0||xx>=row||yy>=row){
				continue;
			}
			temp2=temp1;
			temp2.space=xx*row+yy;
			swap(temp2.f[temp1.space],temp2.f[temp2.space]);//交换空格位置
			if(!color[temp2]){
				temp2.path+=dir[i];
				waiting.push(temp2);
				color[temp2]=true;
			}
		}
	}
	return "unsolveable";
}


int main(){
	puzzle in;
	for(int i=0;i<maxx;i++){
		cin>>in.f[i];
		if(in.f[i]==0){
			in.space=i;
		}
	}
	string ans=bfs(in);
	cout<<ans.size()<<endl; 
	
	return 0;
}
