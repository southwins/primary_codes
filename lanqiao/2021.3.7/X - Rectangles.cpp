#include<iostream>
#include<cstdio>
using namespace std;


float workx(float x1,float x2,float x3,float x4){
	if(x1>x2)swap(x1,x2);
	if(x3>x4)swap(x3,x4);
	if(x1<x3&&x3<x2&&x2<x4)return x2-x3;
	if(x3<x1&&x1<x4&&x4<x2)return x4-x1;
	if(x1<x3&&x3<x4&&x4<x2)return x4-x3;
	if(x3<x1&&x1<x2&&x2<x4)return x2-x1;
	return 0;
}
float worky(float y1,float y2,float y3,float y4){
	if(y1>y2)swap(y1,y2);
	if(y3>y4)swap(y3,y4);
	if(y1<y3&&y3<y2&&y2<y4)return y2-y3;
	if(y3<y1&&y1<y4&&y4<y2)return y4-y1;
	if(y1<y3&&y3<y4&&y4<y2)return y4-y3;
	if(y3<y1&&y1<y2&&y2<y4)return y2-y1;
	return 0;
}

int main(){
	float x1,y1,x2,y2,x3,y3,x4,y4;
	while(cin>>x1>>y1){
		cin>>x2>>y2>>x3>>y3>>x4>>y4;
		float ansx=workx(x1,x2,x3,x4);
		float ansy=worky(y1,y2,y3,y4);
		printf("%.2f\n",ansx*ansy);
	}
	
	return 0;
}
