#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int T,N,M,i,j;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d %d",&N,&M);
        for(j=0;j<M;j++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
        }
        printf("%d\n",N-1);
    }
    return 0;
}
