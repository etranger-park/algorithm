#include <stdio.h>
#include <stdlib.h>

void merge(int *list, int left, int mid, int right){
  int i, j, k, l;
  i = left;
  j = mid+1;
  k = left;
  int sorted[1500000]={0};
  /* ���� ���ĵ� list�� �պ� */
  while(i<=mid && j<=right){
    if(list[i]<=list[j])
      sorted[k++] = list[i++];
    else
      sorted[k++] = list[j++];
  }

  // ���� �ִ� ������ �ϰ� ����
  if(i>mid){
    for(l=j; l<=right; l++)
      sorted[k++] = list[l];
  }
  // ���� �ִ� ������ �ϰ� ����
  else{
    for(l=i; l<=mid; l++)
      sorted[k++] = list[l];
  }

  // �迭 sorted[](�ӽ� �迭)�� ����Ʈ�� �迭 list[]�� �纹��
  for(l=left; l<=right; l++){
    list[l] = sorted[l];
  }
}

// �պ� ����
void merge_sort(int *list, int left, int right){
  int mid;

  if(left<right){
    mid = (left+right)/2;
    merge_sort(list, left, mid);
    merge_sort(list, mid+1, right);
    merge(list, left, mid, right);
  }
}

int main()
{
    int i,n;
    int arr[1500000] = {0};
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }

    return 0;
}
