#include<iostream>
#include<string>
using namespace std;

//链接：https://ac.nowcoder.com/acm/contest/9981/F
//来源：牛客网
//
//考试结束了，牛牛和牛妹开始对答案。
//每道题有 ABCD 四个选项，一共有道题，全部是单选题，每道题正确得 1 分，错误不得分。
//牛牛和牛妹互相知道了他们每道题选择的选项。他们想知道，两个人得分之和有可能达到的最大值和最小值是多少？

int main(){
	int n;
	cin>>n;
	string a(n,0),b(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int count=0;
	for(int i=0;i<n;i++){
		cin>>b[i];
		if(b[i]==a[i])count++;
	}
	cout<<count*2+n-count<<" "<<0<<endl;
	return 0;
}
