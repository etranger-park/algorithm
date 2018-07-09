#include <iostream>
#include <cstdio>
#include <cstdlib>

//Think Coordinate, not matrix

using namespace std;

uint64_t n;
//X coordinga
uint64_t get_value(int x, int y)
{
    uint64_t base, value, sum = (uint64_t) x+y;
    if(sum < n)
    {
        base = sum*(sum+1) /2;
        value = base + (sum % 2 == 0 ? x:y) + 1;

    }
    else
    {
        uint64_t k = 2*n - 1 - sum;
        base = n*n - k*(k+1)/2;
        value = base + (sum % 2 == 0 ? (n-y):(n-x));
    }
    return value;
}

int main()
{
    int x,y,k,i;
    x=0; y=0;
    uint64_t sum = 1;
    char c;
    scanf("%lld %d\n",&n,&k);
    for(i=0;i<k;i++)
    {
        c = getchar();
        switch(c)
        {
            case('D'):
                y++;
                break;
            case('R'):
                x++;
                break;
            case('U'):
                y--;
                break;
            case('L'):
                x--;
                break;
        }
        sum +=get_value(x,y);
        //printf("%c: %llu\n",c,sum);
    }
    printf("%llu",sum);

    return 0;
}
