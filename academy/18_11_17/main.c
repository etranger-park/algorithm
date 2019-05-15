#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,M,K;
    int arr[400][400]= {0};
    scanf("%d %d",&N,&M);
    for(int r=0;r<N;r++)
    {
        for(int c =0;c<M; c++)
        {
            scanf("%d",&arr[r][c]);
        }
    }
    scanf("%d",&K);
    for(int idx=0;idx<K;idx++)
    {
        int i,j,x,y,sum =0;
        scanf("%d %d %d %d",&i,&j,&x,&y);
        for(int r=i-1;r<x;r++)
        {
            for(int c=j-1;c<y;c++)
            {
                sum +=arr[r][c];
            }
        }
        printf("%d\n",sum);
    }
















    /*
    int N;
    int arr[1000] = {0};
    int *ptr1,*ptr2;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    ptr1 = &arr[0];
    ptr2 = &arr[N-1];
    for(int i =0 ; i < N/2;i++)
    {
        ///SWAP
        ptr1++;
        ptr2--;
    }
    for(int i=0;i<N;i++)
    {
        printf("%d ",arr[i]);
    }*/

    return 0;
}
