#include<bits/stdc++.h>
using namespace std;

bool isa(char a) {
	if(a>='a'&&a<='z')return true;
	return false;
}
bool isA(char a) {
	if(a>='A'&&a<='Z')return true;
	return false;
}
bool isn(char a) {
	if(a>='0'&&a<='9')return true;
	return false;
}

int main() {
	int a,b,c;
	cin>>a>>b>>c;
	char s[105];
	scanf("%s[\n]",&s);
	//string s(&s[0],&s[strlen(ss)]);

	for(int i=0; s[i]!=0; i++) {
		if(s[i]=='-'&&i>0) {
			if((isa(s[i-1])&&isa(s[i+1]))||(isA(s[i-1])&&isA(s[i+1]))) {
				if(s[i-1]<s[i+1]) {
					char t='a';
					if(isA(s[i-1])&&isA(s[i+1]))t='A';
					int k=0;
					if(c==1)for(char j=s[i-1]-t+1; j<s[i+1]-t; k++) {
							if(k!=0&&k%b==0) {
								j++;
								if(j==s[i+1]-t)break;
							}
							char temp;
							if(a==1)temp=j+'a';
							else if(a==2)temp=j+'A';
							else if(a==3)temp='*';
							cout<<temp;
						}

					else {
						k=0;
						for(char j=s[i+1]-t-1; j>s[i-1]-t; k++) {
							if(k!=0&&k%b==0) {
								j--;
								if(j==s[i-1]-t)break;
							}
							char temp;
							if(a==1)temp=j+'a';
							else if(a==2)temp=j+'A';
							else if(a==3)temp='*';
							cout<<temp;
						}
					}
				}else cout<<s[i];
			}
			else if(isn(s[i-1])&&isn(s[i+1])) {
				if(s[i-1]<s[i+1]) {
					int k=0;
					if(c==1)for(char j=s[i-1]+1; j<s[i+1]; k++) {
							if(k!=0&&k%b==0) {
								j++;
								if(j==s[i+1])break;
							}
							if(a==3)cout<<'*';
							else cout<<j;
						}

					else {
						k=0;
						for(char j=s[i+1]-1; j>s[i-1]; k++) {
							if(k!=0&&k%b==0) {
								j--;
								if(j==s[i-1])break;
							}
							if(a==3)cout<<'*';
							else cout<<j;
						}
					}
				}else cout<<s[i];
			}else cout<<s[i];
		} else cout<<s[i];
	}
	return 0;
}
