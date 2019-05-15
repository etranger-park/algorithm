#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long int limit, finger, c = 0;
    scanf("%lld",&finger);
    scanf("%lld",&limit);
    if(finger == 1)
        c = 8*limit;
    else if(finger == 5)
        c = 8*limit +4;
    else
    {
        if(limit%2==0)
            c = 4*limit + finger-1;
        else
            c= 4*limit + 5-finger;
    }
    printf("%lld",c);
    return 0;
}
