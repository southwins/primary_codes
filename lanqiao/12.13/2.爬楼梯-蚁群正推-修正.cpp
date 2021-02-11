#include<iostream>
using namespace std;

int count=0;

int yiqun(int n,int now,int total){
	total+=now; //坑点，及时更新本步的total，
	//否则若本层初始(total+now)==n，将会在下层递出两个total==n，导致重复计数 
	if(total==n){
		return 1;
	}
	else if(total>n){
		return 0;
	}
	else{
		return yiqun(n,1,total)+yiqun(n,2,total);
	}
}

int main(){
	cout<<yiqun(15,0,0)<<endl;
	cout<<count<<endl;
	return 0;
} 
 
 
 
