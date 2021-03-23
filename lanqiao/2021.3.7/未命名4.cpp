/*
分析:  
3^0                                
3^1 3^0+3^1                       
3^2 3^0+3^2 3^1+3^2  3^0+3^1+3^2   
规律当前n加进去一个，然后要再加上前面所有的个数 
如果到了某个n,加前面所有的大于N个,就扫下剩下的第几个就行 
时间复杂度O(n) 
f(n)=1+2*f(n-1)   fn表示有几个数目前
f(0)=1;
f(1)=3;
f(2)=7; 
求得大于等于N时的n，然后N-f(n-1)剩下的从左边开始数 
*/
#include <iostream>
#include <cstdio>
using namespace std;
const int N=1000+5;
long long a[N];   //好奇怪改longlong最后一个测试数据会过不去 
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
