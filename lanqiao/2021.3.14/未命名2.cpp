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
    if(alllen==sum)//已经用完所有木棒，正解
    {
        return true;
    }
    if(nowlen==len)//已经拼好一根木棒，继续拼下一根，并从剩下木棒中最长的木棒开始
        nowlen=0, x=1;
    for(int i=x; i<=n; ++i)
    {
        if(vis[i] || nowlen+a[i]>len)//木棒已经用过，木棒无法完成组合
            continue;
        vis[i]=true;
        if(dfs(i, nowlen+a[i], alllen+a[i]))//若此次搜索到正确结过则跳出
        {
            return true;
        }
        vis[i]=false;
        if(nowlen+a[i]==len || nowlen==0)//使用第i根木棒的情况下得不到正解，即第i根木棒无法组合成目标长度，跳出
            return false;
        while(a[i+1]==a[i]) ++i;//第i根木棒无法使用，则与第i根木棒长度相等的均无法使用
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
