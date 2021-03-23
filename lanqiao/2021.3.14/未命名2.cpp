#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 66;
int n, sum, len, a[maxn];
bool flag, vis[maxn];
//int step=0;

bool cmp(int a, int b)
{
    return a>b;
}

bool dfs(int x, int nowlen, int alllen)
{
    if(alllen==sum)//�Ѿ���������ľ��������
    {
        return true;
    }
    if(nowlen==len)//�Ѿ�ƴ��һ��ľ��������ƴ��һ��������ʣ��ľ�������ľ����ʼ
        nowlen=0, x=1;
    for(int i=x; i<=n; ++i)
    {
        if(vis[i] || nowlen+a[i]>len)//ľ���Ѿ��ù���ľ���޷�������
            continue;
        vis[i]=true;
        if(dfs(i, nowlen+a[i], alllen+a[i]))//���˴���������ȷ���������
        {
            return true;
        }
        vis[i]=false;
        if(nowlen+a[i]==len || nowlen==0)//ʹ�õ�i��ľ��������µò������⣬����i��ľ���޷���ϳ�Ŀ�곤�ȣ�����
            return false;
        while(a[i+1]==a[i]) ++i;//��i��ľ���޷�ʹ�ã������i��ľ��������ȵľ��޷�ʹ��
    }
    return false;
}

int main()
{
    while(scanf("%d", &n)!=EOF && n!=0)
    {
        sum=0;
        for(int i=1; i<=n; ++i)
        {
            scanf("%d", &a[i]);
            sum+=a[i];
        }
        sort(a+1, a+n+1, cmp);
        for(len=a[1]; len<=sum; ++len)
        {
            if(sum%len==0)
            {
                //cout<<len<<"..."<<endl;
                memset(vis, false, sizeof(vis));
                if(dfs(1, 0, 0))
                {
                    printf("%d\n", len);
                    break;
                }
            }
        }
    }
    return 0;
}
