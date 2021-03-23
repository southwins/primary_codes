#include<bits/stdc++.h>
using namespace std;

string s,ans(10000,0);
int p1,p2,p3,p;

void work(int i){
	int temp=0;
	if(p1==2&&'a'<=s[i-1]&&s[i-1]<='z'){
		temp=s[i-1]-'a'+'A'+1;//小写换大写 
	}
	else if(p1==3) temp='*';
	else temp=s[i-1]+1;//说明是数字 
	
	int juli=s[i+1]-s[i-1];
	if(p1==3){
		for(int j=0;j<juli-1;j++){
			for(int k=0;k<p2;k++){
				ans[p++]=temp;
			}
		}
	} 
	else {
		if(p3==1){
			for(int j=0;j<juli-1;j++,temp++){//temp自增,比较灵活巧妙 
				for(int k=0;k<p2;k++){
					ans[p++]=temp;
				}
			}
		}
		else {//逆序输出 
			temp+=juli-2;
			for(int j=0;j<juli-1;j++,temp--){
				for(int k=0;k<p2;k++){
					ans[p++]=temp;
				} 
			}
		}
	}
	
}

int main(){
	cin>>p1>>p2>>p3;
	getchar();
	getline(cin,s);
	int len=s.length();
	for(int i=0;i<len;i++){
//		第2行为一行字符串，仅由数字、小写字母和减号“-”组成。行首和行末均无空格。
		if(i-1<0){
			ans[p++]=s[i];
			continue;
		}
		
		if(s[i] != '-' || !(('0'<=s[i-1] && s[i+1]<='9') || 
			('a'<=s[i-1] && s[i+1]<='z'))){
			ans[p++]=s[i];
		}
		else if(s[i-1]<s[i+1]){
			work(i);
		}
		else {
			ans[p++]=s[i];
		}
	}
	cout<<ans<<endl;
	
	return 0;
} 
