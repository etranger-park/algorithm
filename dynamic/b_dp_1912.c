
#include <stdio.h>
#include <stdlib.h>
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

#define N 100001

int min3(int a, int b, int c)
{
    if(a<=b && a<=c) return a;
    else if(b<=a && b<=c) return b;
    else return c;
}

int max3(int a, int b, int c)
{
    if(a>=b && a>=c) return a;
    else if(b>=a && b>=c) return b;
    else return c;
}

int input[N] = { 0 };
int max[N] = {0};

void init(int n)
{
    return;
}

int dp(int n)
{
    if(max[n+1]>0)
    {
        max[n] = max[n+1] + input[n];
    }
    else
    {
        max[n] = input[n];
    }
    return max[n];
}

int main()
{
    int val,i,j,result = -2000,tmp;
    scanf("%d",&val);
    const int n =  val;

    for(i=0;i<n;i++)
    {
        scanf("%d",&input[i]);
    }

    for(i=n-1;i>=0;i--)
    {
        tmp = dp(i);
        if(tmp > result)
            result =tmp;
    }

    printf("%d",result);
    return 0;
}
