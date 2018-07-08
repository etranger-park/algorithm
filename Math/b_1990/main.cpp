#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>

#define TRUE 1
#define FALSE 0

using namespace std;

int next_palindrome(int a)
{
    int i;
    char ca,cb;
    int c;
    string str = std::to_string(a);
    int length = str.length();
    for(i=0;i<length/2;i++)
    {
        str[length-1-i] = str[i];
    }

    if(stoi(str) > a) return stoi(str);

    ca = str.at(length/2);

    if(ca != '9')
    {
        ca = ca + 1;
        if(length % 2 ==0)
            str[length/2 -1] = ca;
        str[length/2] = ca;
        return stoi(str);
    }
    else
    {
        int round_up,down;
        double tmp = (double) a;
        down = length%2 == 0 ? length/2 : length/2 +1;
        for(i=0;i<down;i++)
            tmp /= 10;
        tmp = ceil(tmp);
        for(i=0;i<down;i++)
            tmp *= 10;
        round_up=(int)tmp;
        return next_palindrome(round_up);
    }

    return 0;
}

bool check_prime(int a)
{
    if(a%2 == 0) return false;
    int i,cut;
    cut = (int) ceil(sqrt(a));

    for(i=3;i<cut +1;i=i+2)
    {
        if(a%i == 0)
            return false;
    }

    return true;
}

int main()
{
    int a,b,i,jump = 2;
    scanf("%d %d",&a,&b);

    for(i=a;i<=b;i=next_palindrome(i))
    {
        if(check_prime(i))
            printf("%d\n",i);
    }
    printf("-1");

    return 0;
}
