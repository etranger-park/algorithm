#include <stdio.h>

int main()
{
  int t;
  scanf("%d", &t);
  for(int test_index = 1; test_index <= t; test_index++)
  {
    int n,A = 0,B = 0;
    scanf("%d", &n);
    const int const_n = n;
    int digit = 1;
    while(n > 0)
    {
      if(n % 10 == 4)
      {
        B +=digit;
      }
      n /= 10;
      digit *= 10;
    }
    A = const_n - B;
    printf("Case #%d: %d %d\n",test_index,A,B);
  }
}