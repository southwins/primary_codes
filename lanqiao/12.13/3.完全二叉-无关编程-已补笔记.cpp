#include<iostream>
#include<cmath>
using namespace std;

//what is wanquanercha?
int main(){
	int total=0;
	for(int i=0;;i++){
		total+=pow(2,i);
		if(total==4045){
			cout<<i<<endl;
			cout<<pow(2,i)<<endl;
			break;
		}
		if(total>4045){
			break;
		}
	}
	return 0;
} 
 
