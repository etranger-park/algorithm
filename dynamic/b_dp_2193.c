#include <stdio.h>
#include <stdlib.h>
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

#define N 95

int min(int a, int b, int c)
{
    if(a<=b && a<=c) return a;
    else if(b<=a && b<=c) return b;
    else return c;
}

long long unsigned int arr[N] = { 0 };

void init()
{
    arr[0] = 1;
    arr[1] = 1;
}

void dp(int n)
{
    int i;
    long long unsigned int sum = (long long unsigned int)0;
    for(i=0;i<n-1;i++)
    {
        sum += arr[i];
    }
    arr[n] = sum + 1;//1<<n
}



int main()
{
    int n,i;
    long long unsigned int result;
    scanf("%d",&n);
    init();
    for(i=2;i<n;i++)
        dp(i);

    result = arr[n-1];

    printf("%llu",result);
    return 0;
}
