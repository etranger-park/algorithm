#include <iostream>
#include <set>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int n, input_case,i;
    long long int notation,c;
    int * permutation,index;
    long long int factorial[21] ={ 1 };
    set<int> s;
    set<int>::iterator it;

    scanf("%d",&n);
    scanf("%d",&input_case);

    permutation = (int *)malloc(sizeof(int)*n);

    for(i=1;i<=n;i++)
    {
        //calculate factorial value
        if(i==1)
            factorial[i] = 1;
        else
            factorial[i] = factorial[i-1] * (long long int)i;
    }
    if(input_case == 1)
    {
        //Get Notation return permutation
        scanf("%lld", &notation);
        notation --;

        for(i=1;i<=n;i++)
            s.insert(i);

        for(i=0;i<n;i++)
        {
            index = notation / factorial[n-i-1];
            c=0;
            for(it = s.begin();it!=s.end();it++,c++)
                if(c==index)
                    break;

            *(permutation + i) = *it;
            s.erase(it);
            notation %= factorial[n-i-1];
        }
        for(i=0;i<n;i++)
        {
            printf("%d ",*(permutation + i));
        }
    }
    else if(input_case == 2)
    {
        //Get permutation, return notation
        for(i=0;i<n;i++)
            scanf("%d",permutation+i);
        notation = 1;
        for(i=n-1;i>=0;i--)
        {
            s.insert(*(permutation+i));
            c=0;
            for(it=s.begin();it!=s.end();it++,c++)
                if(*(permutation + i)== *it)
                    break;
            notation += factorial[n-i-1] * c;
        }
        printf("%lld",notation);
    }
    return 0;
}
