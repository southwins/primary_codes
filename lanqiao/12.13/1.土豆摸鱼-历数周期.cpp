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
 
 int juli(int y1,int y2){
 	int total=0;
 	for(int i=y1;i<y2;i++){
 		if(jleapy(i)==1){
 			total+=366;
		 }
		 else total+=365;
		 cout<<"_____"<<total<<endl;
	 }
	 return total;
 }
 
 int main(){
 	int total=0;
 	total+=juli(2010,2020);
 	cout<<total<<endl;
 	total-=daysinyear(2010,6,7);
 	cout<<"-"<<daysinyear(2010,6,7)<<"="<<total<<endl;
 	total+=daysinyear(2020,12,10);
 	cout<<"+"<<daysinyear(2020,12,10)<<"="<<total<<endl;
 	cout<<total/7<<endl;
 	cout<<total%7<<endl;
 	cout<<total/7/5<<endl;//ÿ5���������Ĺ���ģʽ�ִ���һ��һ�����㿪ʼ
	 //ÿ5��������������������Ӧɹ�� 
 	cout<<total/7%5<<endl;//ʣ��3�����ڣ�Ҫ����ǰ��ʣ�µ�4�� 
 	return 0;
 } 
 
 
 
 
 
 
 
 
 
