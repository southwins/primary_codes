#include<iostream>

using namespace std;



int main(){
	int count=0;
	
	for(int i=1;i<=2019;i++){
		for(int j=i;j<=2019;j++){
			for(int k=j;k<2019;k++){
				if(i+j+k==2019&&i!=0&&j!=0&&k!=0){
					count++;
					cout<<i<<" "<<j<<" "<<k<<endl;
				}
			}
		}
	}
	cout<<count<<endl;
	cout<<339697<<endl; 
	return 0;
}
