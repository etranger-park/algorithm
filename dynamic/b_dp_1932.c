
#include <stdio.h>
#include <stdlib.h>
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

#define N 500

int min(int a, int b, int c)
{
    if(a<=b && a<=c) return a;
    else if(b<=a && b<=c) return b;
    else return c;
}

int input[N][N] = {0};
int arr[N][N] = {0};

void init(int n)
{

}

int dp(int n)
{
    //When get the n guarantee that arr[n+1] has the value
    int i;
    for(i=0;i<=n;i++)
    {
        arr[n][i] = MAX(arr[n+1][i],arr[n+1][i+1]) + input[n][i];
    }
    return 0;
}

int main()
{
    int val,i,j,result = 0;
    scanf("%d",&val);
    const int n = val;

    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            scanf("%d",&input[i][j]);
            if(i == n-1)
                arr[n-1][j] = input[n-1][j];//Initializing
        }
    }

    for(i=n-2;i>=0;i--)
    {
        dp(i);
    }

    result = arr[0][0];
    printf("%d",result);
    return 0;
}
