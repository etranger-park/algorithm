#include <stdio.h>
#include <stdlib.h>

# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

int partition(int *list, int left, int right){
    int pivot, tmp;
    int low, high;

    low = left+1;
    high = right;
    pivot = *(list+left); // ������ ����Ʈ�� ���� ���� �����͸� �ǹ����� ����(������ ���� �ǹ����� ����)
    //printf("left:%d, high:%d, pivot:%d\n",left,right,pivot);
    /* low�� high�� ������ ������ �ݺ�(low<high) */
    while(low<=high)
    {
        while (low<=right && *(list+low)<pivot)
        {
            low++;
        }

        while (high>=left && *(list+high)>pivot)
        {
            high--; //high�� right ���� ����
        }
        //printf("new low:%d new_high:%d\n",low,high);
        // ���� low�� high�� �������� �ʾ����� list[low]�� list[high] ��ȯ
        if(low<high)
        {
            tmp = *(list+low);
            *(list+low) = *(list+high);
            *(list+high) =tmp;
        }
    }

    // low�� high�� ���������� �ݺ����� �������� list[left]�� list[high]�� ��ȯ
    tmp = list[left];
    list[left] = list[high];
    list[high] =tmp;
    // �ǹ��� ��ġ�� high�� ��ȯ
    return high;
}

void quick_sort(int *list, int left, int right)
{
  /* ������ ������ 2�� �̻��� �������̸�(����Ʈ�� ũ�Ⱑ 0�̳� 1�� �ƴϸ�) */
    if(left<right)
    {
        // partition �Լ��� ȣ���Ͽ� �ǹ��� �������� ����Ʈ�� ��յ� ���� -����(Divide)
        int q = partition(list, left, right); // q: �ǹ��� ��ġ
        //printf("pivot %d left:%d, right:%d\n",q,left,right);
        int data_it;
        quick_sort(list, left, q-1); // (left ~ �ǹ� �ٷ� ��) ���� �κ� ����Ʈ ���� -����(Conquer)
        quick_sort(list, q+1, right); // (�ǹ� �ٷ� �� ~ right) ���� �κ� ����Ʈ ���� -����(Conquer)
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
    ///�ܹ�ó��
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
        printf("\n\n�Է°�:");
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
        printf("\n��°�:");
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
    printf("�׽�Ʈ �� Ƚ���� �����ּ���\n");
    scanf("%d",&n);
    /*int a,b,temp;
    a=5; b=3;
    SWAP(a,b,temp);
    printf("%d %d",a,b);*/
    test(n);
    return 0;
}
