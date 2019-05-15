#include <iostream>

using namespace std;

int a[10] = {0};
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
    int A,B,C,i;

    cin >> A >> B >> C ;
    check(A*B*C);
    for(i=0;i<10;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
