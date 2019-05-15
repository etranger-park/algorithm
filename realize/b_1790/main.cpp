#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int digit(int a)
{
    int c,i;
    c=0;i=1;
    while(i<=a)
    {
        i*=10;
        c++;
    }
    return c;
}
//return a^b
uint64_t pow(int a,int b)
{
    uint64_t i,result=1;
    for(i=0;i<b;i++)
    {
        result *=10;
    }
    return result;
}

int limit(int n)
{
    //Get limit k when given n
    int a = digit(n);
    int i,result=0,k;
    for(i=0;i<a-1;i++)
    {
        k=pow(10,i+1) - pow(10,i);
        result += (i+1)*k;
    }
    result += a*(n - pow(10,a-1) + 1);
    return result;
}

int get_num(int n,int k)
{
    int a = digit(n);
    uint64_t base,i,p,num = (uint64_t) k;

    for(i=0;i<a;i++)
    {
        p = pow(10,i+1) - pow(10,i);
        if(num > p*(i+1)) num -= (p*(i+1));
        else break;
    }
    base =pow (10,i) - 1 + num/(i+1);
    if(num % (i+1) == 0)
    {
        return base%10;
    }
    else
    {
        string s = to_string(base+1);
        return (s[(num % (i+1)) - 1])-'0';
    }
}

int main()
{
    int n,k,result;
    scanf("%d %d",&n,&k);
    if(limit(n) < k )
    {
        printf("-1");
        return 0;
    }
    result = get_num(n,k);
    printf("%d",result);
    return 0;
}
