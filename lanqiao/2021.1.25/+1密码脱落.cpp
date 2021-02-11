#include<iostream>
#include<string>
#include<algorithm> 
using namespace std;

int maxc[1001][1001];

int main() {
	string s1,s2;
	while(cin>>s1){
		s2=s1;
		reverse(s2.begin(),s2.end());
		s1="0"+s1,s2="1"+s2;
		int len1=s1.length(),len2=s2.length();
	for(int i=0; i<len1; i++) {
		for(int j=0; j<len2; j++) {
			maxc[i][j]=0;
		}
	}
	for(int i=1; i<len1; i++) {
		maxc[i][0]=0;
	}
	for(int j=1; j<len2; j++) {
		maxc[0][j]=0;
	}
	for(int i=1; i<len1; i++) {
		for(int j=1; j<len2; j++) {
			if(s1[i]==s2[j]) {
				maxc[i][j]=maxc[i-1][j-1]+1;
			} else if(maxc[i-1][j]>maxc[i][j-1]) {
				maxc[i][j]=maxc[i-1][j];
			} else maxc[i][j]=maxc[i][j-1];
		}
	}
	cout<<len1-1-maxc[len1-1][len2-1]<<endl;
	}
	
	return 0;
}
