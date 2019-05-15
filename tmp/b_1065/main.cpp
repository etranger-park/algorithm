#include <iostream>
#include <stdio.h>

using namespace std;

char check_han(int n)
{
    if(n<100) return 1;
    int prev,next;
    prev = n%10;
    n/=10;
    next = n%10;
    int flag = prev - next; //십의 자리와 일의 자리의 차
    while(n >0)
    {
        next = n%10;
        if(flag != prev - next)
            return 0;
        n/=10;
        prev = next;
    }
    return 1;
}

int main()
{
    int i,N;
    int result = 0;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        if(check_han(i))
            result++;
    }
    printf("%d",result);
    return 0;
}
