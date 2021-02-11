#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int*team=new int[n];
	memset(team,0,n*sizeof(int));
	for(int i=0;i<m;i++){
		int l,r;
		cin>>l>>r;
		team[l]++,team[r]--;
	}
	
	return 0;
}
