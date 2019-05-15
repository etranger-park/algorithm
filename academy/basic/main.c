#include <stdio.h>
#include <stdlib.h>

int get_tricky(int n)
{
    int d,o, new_d,new_o;
    if(n<10) return 11*n;
    else
    {
        o = n % 10;
        d = n / 10;
        new_o = (o+d)%10;
        new_d = o;
        return new_d *10 + new_o;
    }
}

int main()
{
    int N;
    int i = 0;
    int tricky;
	scanf("%d",&N);
    int count = 0;
	tricky = N;
    while(1)
    {
        count++;
        tricky = get_tricky(tricky);
        if(N == tricky)
            break;
    }
	printf"%d",count);
    return 0;
}
