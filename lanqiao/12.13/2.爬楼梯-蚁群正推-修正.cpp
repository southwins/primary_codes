#include<iostream>
using namespace std;

int count=0;

int yiqun(int n,int now,int total){
	total+=now; //�ӵ㣬��ʱ���±�����total��
	//�����������ʼ(total+now)==n���������²�ݳ�����total==n�������ظ����� 
	if(total==n){
		return 1;
	}
	else if(total>n){
		return 0;
	}
	else{
		return yiqun(n,1,total)+yiqun(n,2,total);
	}
}

int main(){
	cout<<yiqun(15,0,0)<<endl;
	cout<<count<<endl;
	return 0;
} 
 
 
 
