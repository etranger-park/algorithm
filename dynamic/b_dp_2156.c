#include <stdio.h>
#include <stdlib.h>
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

#define N 10001

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
int next_drink[N] = { 0 };
int next_pass[N] = { 0 };
int max_amount[N] = {0};

void init(int n)
{
    next_drink[n-1] = input[n-1];
    next_pass[n-1] = input[n-1];
    max_amount[n-1] = input[n-1];
    return;
}

int dp(int n)
{
    next_drink[n] = input[n] + next_pass[n+1];
    next_pass[n] = input[n] + max_amount[n+2];
    max_amount[n] =max3(max_amount[n+1],next_drink[n],next_pass[n]);
    return 0;
}

int main()
{
    int val,i,j,result = 0;
    scanf("%d",&val);
    const int n =  val;

    for(i=0;i<n;i++)
    {
        scanf("%d",&input[i]);
    }

    init(n);

    for(i=n-2;i>=0;i--)
    {
        dp(i);
    }

    result = max_amount[0];
    printf("%d",result);
    return 0;
}
