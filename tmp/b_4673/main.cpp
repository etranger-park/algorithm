#include <iostream>
#include <stdio.h>

using namespace std;
const int MAX_N = 10001;
char check[MAX_N] = {0};
int find_self_num(int n)
{
    int result = n;
    while(n>0)
    {
        result += n%10;
        n/=10;
    }
    return result;
}

int main()
{
    int i,j;
    for(i=1;i<MAX_N;i++)
    {
        int d_n = find_self_num(i);
        check[d_n] = 1;
    }
    for(i=1;i<MAX_N;i++)
    {
        if(check[i]==0)
            printf("%d\n",i);
    }

    return 0;
}
