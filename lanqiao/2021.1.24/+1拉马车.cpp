#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int shuitong[300];
char shunxu[66];

void showq(queue<char>&q) {
	while(!q.empty()) {
		cout<<q.front();
		q.pop();
	}
	cout<<endl;
}

void print(char*p,int n){
	for(int i=0;i<n;i++){
		cout<<endl<<p[i]<<endl;
	}
}


int main() {
	queue<char>q1,q2;
	char a;
	int k=0;
	while(scanf("%c",&a)!=EOF) {
		if(a=='\n') {
			k++;
			if(!(k&1)&&k!=0) {
				memset(shunxu,0,66);
				memset(shuitong,0,300);
				for(int i=0,count=0;; i++) {
					flag:
					if(i>900){
						cout<<-1<<endl;
						break;
					}
					if(q2.empty()||q1.empty()) {
						if(q2.empty()) {
							showq(q1);
						} else showq(q2);
						break;
					}
					char now=0;
					if(i&1)now=q2.front();
					else now=q1.front();

					if(shuitong[now]) {
						if(i&1)q2.push(now);
						else q1.push(now);
						for(; count>=0;) {
							char shou=shunxu[count-1];
							shunxu[--count]=0;
							shuitong[shou]--;
							if(i&1)q2.push(shou);
							else q1.push(shou);
							if(shou==now) {
								if(i&1)q2.pop();
								else q1.pop();
								goto flag;
							}
						}
					} else {
						shuitong[now]++;
						shunxu[count++]=now;
					}

					if(i&1)q2.pop();
					else q1.pop();
				}
			}
			continue;
		}
		if(k&1) {
			q2.push(a);
		} else {
			q1.push(a);
		}
	}

	return 0;
}
