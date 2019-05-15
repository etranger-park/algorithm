#include <iostream>
#include <cstdio>
#include <vector>
#define MAX_M 1000001
#define MAX_N 1000001

using namespace std;

int main()
{
    int Z,N,M;
    scanf("%d",&Z);
    while(Z > 0)
    {
        --Z;
        int i,c=0;
        int t[MAX_M];
        scanf("%d %d",&N,&M);
        for(i = 0;i<M;i++)
        {
            scanf("%d",t+i);
            if(t[i]==0)
                c++;
            else
                c--;
        }

        if(t[0]>0 || c<0)
        {
            printf("NO\n");
            continue;
        }
        bool flag = false;
        for(i=1;i<M;i++)
        {
            if(t[i]!=0 && t[i]==t[i-1])
            {
                flag = true;
                break;
            }

        }
        if(flag)
        {
            printf("NO\n");
            continue;
        }


    }
    return 0;
}
