#include<bits/stdc++.h>
using namespace std;

string s,ans(10000,0);
int p1,p2,p3,p;

void work(int i){
	int temp=0;
	if(p1==2&&'a'<=s[i-1]&&s[i-1]<='z'){
		temp=s[i-1]-'a'+'A'+1;//Сд����д 
	}
	else if(p1==3) temp='*';
	else temp=s[i-1]+1;//˵�������� 
	
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
			for(int j=0;j<juli-1;j++,temp++){//temp����,�Ƚ�������� 
				for(int k=0;k<p2;k++){
					ans[p++]=temp;
				}
			}
		}
		else {//������� 
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
//		��2��Ϊһ���ַ������������֡�Сд��ĸ�ͼ��š�-����ɡ����׺���ĩ���޿ո�
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
