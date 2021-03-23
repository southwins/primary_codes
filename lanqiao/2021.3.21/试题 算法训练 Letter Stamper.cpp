#include<bits/stdc++.h>
using namespace std;

char s[2005];
int a,b,c,sum;
int flag[500];

int main() {
	int n;
	cin>>n;
	getchar();
	int nn=n;
	while(n--) {
		memset(s,0,2005);
		sum=a=b=c=0;
		flag['A']=flag['B']=flag['C']=0;
		while(scanf("%c",&s[sum])&&s[sum]!='\n') {
			if(s[sum]=='A')a++;
			else if(s[sum]=='B')b++;
			else c++;
			sum++;
		}
		
		int total=0,last=0;
		char temp[3];
		memset(temp,0,3);
		for(int i=0; i<sum; i++) {
			int t=0;
//			cout<<endl<<temp[last-1]<<endl;
			if(temp[last-1]==s[i]){
				total+=1;
//				cout<<1<<endl;
			}
			else {
				if(flag[s[i]]){
					while(temp[last-1]!=s[i]){
//						cout<<endl<<temp[last-1]<<endl;
						flag[temp[last-1]]=0;
						last--;
						total+=1;
//						cout<<"--"<<1<<endl;
					}
					total+=1;
//					cout<<1<<endl;
					t=1;
				}
				else{
					temp[last++]=s[i];
					flag[s[i]]=1;
					total+=2;
//					cout<<2<<endl;
				}
			}
			if(!t)if((s[i]=='A'&&a==1)
				||(s[i]=='B'&&b==1)
				||(s[i]=='C'&&c==1)
				){
					total+=1;
					last--;
//					cout<<"--"<<1<<endl;
				}
			if(s[i]=='A')a--;
			else if(s[i]=='B')b--;
			else c--;
		}
		cout<<"Case #"<<nn-n<<": "<<total<<endl;
	}
	return 0;
}
