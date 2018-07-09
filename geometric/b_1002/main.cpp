#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define EPS 1e-6

using namespace std;

int get_num(int x1, int y1, int r1, int x2, int y2, int r2)
{
    double distance;
    if(x1==x2 && y1==y2 && r1 == r2) return -1;
    distance = sqrt((double)((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
    double r_sum = (double)(r1+r2);
    double r_diff =abs((double)(r1-r2));
    if(abs(r_sum-distance)<EPS || abs(r_diff-distance)<EPS ) return 1;
    else if(r_sum>distance && r_diff < distance ) return 2;
    else return 0;
}

int main()
{
    int n,i,x1,y1,r1,x2,y2,r2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
        printf("%d\n",get_num(x1,y1,r1,x2,y2,r2));
    }
    return 0;
}
