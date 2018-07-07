#include <stdio.h>
#include <stdlib.h>
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

#define N 1001

int min(int a, int b, int c)
{
    if(a<=b && a<=c) return a;
    else if(b<=a && b<=c) return b;
    else return c;
}

int arr[N] = { 0 };

void init()
{
    arr[0] = 1;
    arr[1] = 2;
}

//Set the arr[n] using under algorithm
int dp(int n)
{
    if(arr[n] > 0 ) return arr[n];
    arr[n] = (dp(n-1) + dp(n-2)) % 10007;
    return arr[n];
}

int main()
{
    int n,i,result = 0;
    scanf("%d",&n);
    init();
    for(i=2;i < n ;i++)
        dp(i);
    result = arr[n-1];
    printf("%d",result);
    return 0;
}
