 #include<iostream>
 using namespace std;
 
 int mth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
 
 int jleapy(int a){
 	if(a%4==0&&a%100!=0){
 		return 1;
	 }
	if(a%400==0){
		return 1;
	}
	return 0;
 }
 
 int daysinyear(int y,int m,int d){
 	int total=0;
 	for(int i=1;i<m;i++){
 		total+=mth[i];
	 }
	 
 	if(jleapy(y)==1&&m>2){
 		return total+1+d;
	 }
	 else return total+d;
 }
 
 int main(){
 	int t;
 	cin>>t;
 	while(t--){
 		int c1=0,c2=0;
 		int y,m,d;
 		cin>>y>>m>>d;
		int t1=daysinyear(y,m,d),t2=daysinyear(y,12,13);
 		c1=daysinyear(y-1,12,31)-daysinyear(y-1,12,13)+t1;
 		if(t1>t2){
 			int temp=t1;
 			t1=t2;
 			t2=temp;
		 }
		 c2=t2-t1;
		 cout<<(c1<c2?c1:c2)<<endl;
	}
 	return 0;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
