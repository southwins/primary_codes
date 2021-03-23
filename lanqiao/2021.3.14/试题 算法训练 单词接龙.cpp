#include<bits/stdc++.h>
using namespace std;

int n,allen;
string str[25];
int vis[25];

int check(string a,string b) {
	int al=a.length(),bl=b.length();
	for(int i=1;(i<al&&i<bl)||(al==1&&i<=al);i++) {
		string aa(a.substr(al-i)),bb(b.substr(0,i));
		if(aa==bb){
			return i;
		}
	}
	return 0;
}

void dfs(string now,int now_len) {
	if(now_len>allen)allen=now_len;
	for(int i=0; i<n; i++) {
		if(vis[i]>1)continue;
		int c=check(now,str[i]);
		if(c>0) {
			vis[i]++;
			string newone(now+str[i].substr(c));
			dfs(newone,now_len+str[i].length()-c);
			vis[i]--;
		}
	}
}

int main() {
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>str[i];
	}
	cin>>str[n];

	dfs(str[n],1);
	cout<<allen<<endl;

	return 0;
}
