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
        quick_sort(list, left, q-1); // (left ~ 피벗 바로 앞) 앞쪽 부분 리스트 정렬 -정복(Conquer)
        quick_sort(list, q+1, right); // (피벗 바로 뒤 ~ right) 뒤쪽 부분 리스트 정렬 -정복(Conquer)
    }
}


void merge_sort(int *src,int src_len,int *dst)
{
    int mid = src_len/2;
    int dst1[200];
    int dst2[200];
    merge_sort(src,mid,dst1);
    merge_sort(src+mid,len-mid,dst2);
    int *ptr1, *ptr2;
    int i;

    for(ptr1 = dst1,ptr2 = dst2;ptr1<dst1+mid &&ptr2 <dst2+(len-mid); )
    {
        if(*(ptr1)<*(ptr2))
        {
            *(dst+i) = *ptr1;
            ptr1++;
        }
        else
        {
            *(dst+i) = *ptr1;
            ptr2++;
        }
        i++;
    }
    ///잔반처리
}



void insert_sort(int *arr,int len)
{
    int i,j;
    for(i=1;i<len;i++)
    {
        int target = *(arr+i);
        for(j=i-1;j>=0;j--)
        {
            if(*(arr+j)>target)
                *(arr+j+1) = *(arr+j); //push the data
            else
                break;
        }
        //set the target value
        *(arr+j+1) = target;
    }
}

void select_sort(int *arr,int len)
{
    int i,j;
    for(i=len-1;i>=0;i--)
    {
        int max = -100000000;
        int index = -1;
        for(j=0;j<=i;j++)
        {
            if(max<*(arr+j))
            {
                max = *(arr+j);
                index = j;
            }
        }
        //swap
        int tmp = *(arr+i); //last
        *(arr+i) = *(arr+index); //max value
        *(arr+index) = tmp;
    }
}

void bubble_sort(int *arr,int len)
{
    int i,j;
    for(i=len-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(*(arr+j)>*(arr+j+1))
            {
                //swap
                int tmp = *(arr+j); //arr[j]
                *(arr+j) = *(arr+j+1); // arr[j] = arr[j+1]
                *(arr+j+1)= tmp;
            }
        }

    }
}


void test(int n)
{
    int arr[110] = {0};
    const int data_num = 30;
    int i,it_data;
    for(i=0;i<n;i++)
    {
        printf("\n\n입력값:");
        for(it_data=0;it_data<data_num;it_data++)
        {
            int data = rand();
            arr[it_data]=data;
            printf(" %d",data);
        }
        //bubble_sort(arr,data_num);
        //select_sort(arr,data_num);
        //insert_sort(arr,data_num);
        //quick_sort(arr,0,data_num-1);
        merge_sort(arr,0,data_num-1);
        int check = -1;
        printf("\n출력값:");
        for(it_data=0;it_data<data_num;it_data++)
        {
            if(check>arr[it_data])
            {
                printf("Error!! \n");
            }
            check = arr[it_data];
            printf(" %d",arr[it_data]);
        }
    }
}

int main()
{

    int n;
    printf("테스트 할 횟수를 적어주세요\n");
    scanf("%d",&n);
    /*int a,b,temp;
    a=5; b=3;
    SWAP(a,b,temp);
    printf("%d %d",a,b);*/
    test(n);
    return 0;
}
