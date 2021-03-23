#include<cstdio>
using namespace std;
int main() {
	int n,m,i,j,time=0,a[10000]= {0};
	scanf("%d%d",&n,&m);
	
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);

	for(i=m; i<n; i++) {
		int min=0;
		for(j=1; j<m; j++)
			if(a[j]<a[min])
				min=j;
		a[min]+=a[i];
		printf("%d\n",min);
	}
	
	for(i=0; i<m; i++)
		time=time>a[i]?time:a[i];

	printf("%d\n",time);
}


