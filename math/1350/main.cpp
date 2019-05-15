#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    long long int file_num, cluster_size,i;
    long long int *file;
    long long int real_size = (long long int)0;
    scanf("%lld",&file_num);
    file = (long long int *)malloc(sizeof(long long int)*file_num);

    for(i=0;i<file_num;i++)
        scanf("%lld",file + i);

    scanf("%lld",&cluster_size);

    for(i=0;i<file_num;i++)
    {
        long long int file_size = *(file + i);
        if(file_size % cluster_size == 0)
        {
            real_size += file_size;
        }
        else
        {
            real_size += (long long int)((file_size / cluster_size + 1) * cluster_size);
        }
    }
        printf("%lld",real_size);
    return 0;
}
