#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long int find2(long long int a)
{
    long long int sum = 0, i = 2;
    while(i <= a)
    {
        sum = sum + a/i;
        i*=2;
    }
    return sum;
}

long long int find5(long long int a)
{
    long long int sum = 0, i = 5;
    while(i <= a)
    {
        sum = sum + a/i;
        i*=5;
    }
    return sum;
}
int main()
{
    long long int n,m,n_5,n_2,m_5,m_2,t_5,t_2,result;
    scanf("%lld %lld",&n,&m);

    n_5 = find5(n);
    n_2 = find2(n);
    m_5 = find5(m);
    m_2 = find2(m);
    t_5 = find5(n-m);
    t_2 = find2(n-m);

    result = min(n_5-m_5-t_5, n_2-m_2-t_2);
    printf("%lld",result);
    return 0;
}
