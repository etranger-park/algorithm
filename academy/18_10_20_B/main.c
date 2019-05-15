#include <stdio.h>
#include <stdlib.h>
/*
문제1
길이가 5인 int형 변수 arr을 선언하고, 이를 1,2,3,4,5로 초기화한 다음,
이 배열의 첫 번째 요소를 가리키는 포인터 변수 ptr을 선언한다.
그 다음 포인터 변수 ptr에 저장된 값을 증가시키는 형태의 연산을 기반으로 배열요소에 접근하면서
모든 배열요소의 값을 2씩 증가시키고,정상적으로 증가가 이뤄졌는지 확인하는 예제를 작성해보자.

*/

int main()
{
    int arr[5]= {1,2,3,4,5};
    int i;
    //문제 2번

    /*
    int *ptr = &(arr[0]);
    for(i=0;i<5;i++)
    {
        *(ptr+i)+=2;
        printf("%d ",*(ptr+i));
    }*/
    //ptr 변한다.
    /*
    for(;ptr<(arr+5);ptr++)
    {
        *(ptr)=*(ptr)+2;
        printf("%d ",*ptr);
    }*/
    int *ptr = &(arr[4]);
    int sum=0;
    for(i=0;i<4;i++)
    {
        sum+=*(ptr-i);
    }
    printf("%d",sum);
    return 0;
}
