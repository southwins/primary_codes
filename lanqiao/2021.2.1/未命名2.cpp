#include<iostream>
#include<string>
using namespace std;

//���ӣ�https://ac.nowcoder.com/acm/contest/9981/F
//��Դ��ţ����
//
//���Խ����ˣ�ţţ��ţ�ÿ�ʼ�Դ𰸡�
//ÿ������ ABCD �ĸ�ѡ�һ���е��⣬ȫ���ǵ�ѡ�⣬ÿ������ȷ�� 1 �֣����󲻵÷֡�
//ţţ��ţ�û���֪��������ÿ����ѡ���ѡ�������֪���������˵÷�֮���п��ܴﵽ�����ֵ����Сֵ�Ƕ��٣�

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
