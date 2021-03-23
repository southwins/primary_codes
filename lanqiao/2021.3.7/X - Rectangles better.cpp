#include "iostream"
#include "algorithm"
#include "cstdio"
#include "cmath"
using namespace std;

int main()
{
    double m,n,area;
    double x1,x2,x3,x4,y1,y2,y3,y4,a[4],b[4];
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4)
    {
        a[0]=x1;a[1]=x2;a[2]=x3;a[3]=x4;
        b[0]=y1;b[1]=y2;b[2]=y3;b[3]=y4;
        sort(a,a+4);
        sort(b,b+4);
        m=fabs(x1-x2)+fabs(x3-x4)-(a[3]-a[0]);
        n=fabs(y1-y2)+fabs(y3-y4)-(b[3]-b[0]);
        area=m*n;
        if (m<0||n<0)
        {
            area=0;
        }
        printf("%.2lf\n",area);
    }
    return 0;
}
