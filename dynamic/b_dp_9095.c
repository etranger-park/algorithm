#include <stdio.h>
#include <stdlib.h>

int arr[11] = { 0 };
void init()
{
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
}

int dp(int n)
{
    if(arr[n] > 0) return arr[n];
    arr[n] = dp(n-1) + dp(n-2) + dp(n-3);
    return arr[n];
}
int main()
{
    int n,i,max = 0;
    int *input;
    scanf("%d",&n);
    input = (int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",input+i);
        if(max < *(input + i)) max = *(input + i);
    }
    init();
    for(i=4;i<=max;i++)
    {
        dp(i);
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[*(input+i)]);
    }

    return 0;
}

