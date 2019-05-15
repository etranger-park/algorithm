#include <iostream>

using namespace std;

char a[81];

void check(int num)
{
    while(num > 0)
    {
        int n = num % 10;
        a[n] ++;
        num /=10;
    }
}

int main()
{
    int i,A;
    cin >>A;
    for(i=0;i<A;i++){
        scanf("%s",)
    }
    return 0;
}
