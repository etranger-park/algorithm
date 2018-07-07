
#include <stdio.h>
#include <stdlib.h>
#define MAX 30000

short arr[1000001] = { 0 };

void init()
{
    arr[2] = 1;
    arr[3] = 1;
}

short min(short a,short b,short c)
{
    if(a<=b && a <=c) return a;
    else if(b<=a && b <=c ) return b;
    else return c;
}

short findMin(int n)
{
    short divideBy2, divideBy3,minus, result;
    if(arr[n] != 0) return arr[n];
    if(n <= 1) return 0;

    divideBy2 = n % 2 == 0 ? (arr[n/2] != 0 ? arr[n/2]: findMin(n/2)) : MAX;
    divideBy3 = n % 3 == 0 ? (arr[n/3] != 0 ? arr[n/3]: findMin(n/3)) : MAX;
    minus = arr[n-1] != 0 ? arr[n-1]: findMin(n-1);
    result = min(divideBy2,divideBy3,minus) + 1; //Need one more step
    arr[n] = result;
    return result;
}

int main()
{
    int n,i;
    short result;
    init();
    scanf("%d",&n);

    for(i=2;i<n;i++)
        result = findMin(i);

    result = findMin(n);
    printf("%d",result);
    return 0;
}
