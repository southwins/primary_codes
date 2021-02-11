#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main(){
	stack<int>s1;
	stack<pair<int,int> >s2;//
	string a;
	cin>>a;
	
	int total=0;
	for(int i=0;i<a.length();i++){
		if(a[i]=='\\'){
			s1.push(i);
		}
		else if(a[i]=='/'&&!s1.empty()){
			int j=s1.top();s1.pop();
			int a=i-j;
			total+=a;
			
			while(!s2.empty()&&j<s2.top().first){
				a+=s2.top().second;
				s2.pop();
			}
			
			s2.push(make_pair(j,a));
			
		}
	}
	cout<<total<<endl;
	
	vector<int>ans;
	while(!s2.empty()){
		ans.push_back(s2.top().second);
		s2.pop();
	}
	
	int len=ans.size();
	cout<<len;
	for(int i=len-1;i>=0;i--){
		cout<<" "<<ans[i];
	}
	cout<<endl;
	return 0;
} 
