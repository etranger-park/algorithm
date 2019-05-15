#include <stdio.h>
#include <stdlib.h>
void swap(int* a,int* b)
{

    int tmp;
    tmp = *a;
    (*a)=(*b);
    (*b)=tmp;
}

int main()
{
    int x = 1;
    printf("%d",x&(x-1));
    return 0;
}
/*
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
}*/



