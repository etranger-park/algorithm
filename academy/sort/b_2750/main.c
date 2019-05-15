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
        /*for(data_it=left;data_it<=right;data_it++)
        {
            printf("%d ",*(list+data_it));
        }
        printf("\n");*/
        // �ǹ��� ������ 2���� �κ� ����Ʈ�� ������� ��ȯ ȣ��
        quick_sort(list, left, q-1); // (left ~ �ǹ� �ٷ� ��) ���� �κ� ����Ʈ ���� -����(Conquer)
        quick_sort(list, q+1, right); // (�ǹ� �ٷ� �� ~ right) ���� �κ� ����Ʈ ���� -����(Conquer)
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
