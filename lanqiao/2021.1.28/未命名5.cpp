#include<iostream>

#define INF 0x3f3f3f3f
using namespace std;


struct qujian {
	int min,max;
} q[100000];
int youxiao[100000],cmin[1000000],cmax[1000000];

int count;

bool unite(int aa) {
	//cout<<aa<<endl;
	if(cmin[aa+1]&&cmax[aa-1]);
	else return false;
	int pre,aft;
	for(int j=0,k=0;j<=100000; j++) {
		if(k==count)break;
		if(youxiao[j]==0)continue;
		k++;
		if(q[j].min-1==aa) {
			aft=j;
			cmin[q[j].min]--;
		}
		if(q[j].max+1==aa) {
			pre=j;
			youxiao[j]=0;
			count--;
			cmax[q[j].max]--;
		}
	}
	q[aft].min=q[pre].min;
	return true;
}

int a[100000];
int main() {
	int n;
	cin>>n;
	int min=INF,max=0;
	for(int i=0; i<n; i++) {
		cin>>a[i];
//		for(int j=0,k=0;; j++) {
//			if(k==count)break;
//			if(youxiao[j]==0)continue;
//			k++;
//			cout<<q[j].min<<" "<<q[j].max<<"   ";
//		}
//		cout<<endl;
		if(a[i]!=0&&cmin[a[i]+1]&&cmax[a[i]-1]) {
			unite(a[i]);
			continue;
		} else if(cmin[a[i]+1]) {
			for(int j=0,k=0;; j++) {
				if(k==count)break;
				if(youxiao[j]==0)continue;
				k++;
				if(a[i]+1==q[j].min) {
					cmin[a[i]+1]--;
					q[j].min=a[i];
					cmin[a[i]]++;
					break;
				}
			}
			continue;
		} else if(a[i]!=0&&cmax[a[i]-1]) {
			for(int j=0,k=0;; j++) {
				if(k==count)break;
				if(youxiao[j]==0)continue;
				k++;
				if(a[i]-1==q[j].max) {
					cmax[a[i]-1]--;
					q[j].max=a[i];
					cmin[a[i]]++;
					break;
				}
			}
			continue;
		} else {
			int flag=0;
			for(int j=0,k=0;; j++) {
				if(k==count)break;
				if(youxiao[j]==0)continue;
				k++;
				if(a[i]>=q[j].min&&a[i]<=q[j].max) {
					a[i]=q[j].max+1;
					bool isu=unite(a[i]);
					if(!isu) {
						cmax[q[j].max]--;
						q[j].max=a[i];
						cmax[q[j].max]++;	
					}
					flag=1;
					break;
				}
			}
			if(flag)continue;
		}
		for(int j=0; j<=100000; j++) {
			if(youxiao[j]==0) {
				q[j].max=q[j].min=a[i];
				cmin[a[i]]++,cmax[a[i]]++;
				count++;
				youxiao[j]=1;
				break;
			}
		}
	}
	for(int i=0; i<n; i++) {
		if(i!=0)cout<<" ";
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
