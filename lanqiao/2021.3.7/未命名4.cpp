/*
����:  
3^0                                
3^1 3^0+3^1                       
3^2 3^0+3^2 3^1+3^2  3^0+3^1+3^2   
���ɵ�ǰn�ӽ�ȥһ����Ȼ��Ҫ�ټ���ǰ�����еĸ��� 
�������ĳ��n,��ǰ�����еĴ���N��,��ɨ��ʣ�µĵڼ������� 
ʱ�临�Ӷ�O(n) 
f(n)=1+2*f(n-1)   fn��ʾ�м�����Ŀǰ
f(0)=1;
f(1)=3;
f(2)=7; 
��ô��ڵ���Nʱ��n��Ȼ��N-f(n-1)ʣ�µĴ���߿�ʼ�� 
*/
#include <iostream>
#include <cstdio>
using namespace std;
const int N=1000+5;
long long a[N];   //����ָ�longlong���һ���������ݻ����ȥ 
int main()
{
    int n,i,len; 
    int now,k;   //k^i
    while(cin>>k>>n){
    	len=0;
    	now=1;
        while(len<n){
        	int tmp=len;
        	a[len++]=now;
        	for(i=0;i<tmp&&len<n;i++)
        		a[len++]=now+a[i];    	  
        	now*=k;
		}
		cout<<a[n-1]<<endl;
	}
    return 0;
}
