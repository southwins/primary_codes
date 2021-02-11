#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int flag[100],num;
int fpair(int a) {
	if(a>10) {
		int temp=(int)sqrt(a);
		flag[num++]=temp;
		return fpair(a-temp*temp);
	}
	else return a;
}

int main() {
	int k;
	cin>>k;
	int last=fpair(k);
	string ans;
	if(k==0){
		ans=")(";
	}
	else if(num>0) {
		string a(flag[0],'(');
		string b(flag[0],')');
		ans+=a+b;
		//cout<<flag[0]<<endl;
		for(int i=1; i<num; i++) {
			//cout<<flag[i]<<endl;
			string temp(flag[i],'(');
			ans.insert(ans.size()-flag[i],temp);
		}
		//cout<<last<<endl;
		if(last!=0)ans.insert(ans.size()-last,"(");
	}
	else {
		string a(last,')');
		ans="("+a;
	}
	cout<<ans<<endl;
	return 0;
}
