#include <stdio.h>
#include <stdlib.h>

# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

int partition(int *list, int left, int right){
    int pivot, tmp;
    int low, high;

    low = left+1;
    high = right;
    pivot = *(list+left); // 정렬할 리스트의 가장 왼쪽 데이터를 피벗으로 선택(임의의 값을 피벗으로 선택)
    //printf("left:%d, high:%d, pivot:%d\n",left,right,pivot);
    /* low와 high가 교차할 때까지 반복(low<high) */
    while(low<=high)
    {
        while (low<=right && *(list+low)<pivot)
        {
            low++;
        }

        while (high>=left && *(list+high)>pivot)
        {
            high--; //high는 right 에서 시작
        }
        //printf("new low:%d new_high:%d\n",low,high);
        // 만약 low와 high가 교차하지 않았으면 list[low]를 list[high] 교환
        if(low<high)
        {
            tmp = *(list+low);
            *(list+low) = *(list+high);
            *(list+high) =tmp;
        }
    }

    // low와 high가 교차했으면 반복문을 빠져나와 list[left]와 list[high]를 교환
    tmp = list[left];
    list[left] = list[high];
    list[high] =tmp;
    // 피벗의 위치인 high를 반환
    return high;
}

void quick_sort(int *list, int left, int right)
{
  /* 정렬할 범위가 2개 이상의 데이터이면(리스트의 크기가 0이나 1이 아니면) */
    if(left<right)
    {
        // partition 함수를 호출하여 피벗을 기준으로 리스트를 비균등 분할 -분할(Divide)
        int q = partition(list, left, right); // q: 피벗의 위치
        //printf("pivot %d left:%d, right:%d\n",q,left,right);
        int data_it;
        /*for(data_it=left;data_it<=right;data_it++)
        {
            printf("%d ",*(list+data_it));
        }
        printf("\n");*/
        // 피벗은 제외한 2개의 부분 리스트를 대상으로 순환 호출
        quick_sort(list, left, q-1); // (left ~ 피벗 바로 앞) 앞쪽 부분 리스트 정렬 -정복(Conquer)
        quick_sort(list, q+1, right); // (피벗 바로 뒤 ~ right) 뒤쪽 부분 리스트 정렬 -정복(Conquer)
    }
}

int main()
{

    int i,n;
    int arr[2000000] = {0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    quick_sort(arr,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }

    return 0;
}
