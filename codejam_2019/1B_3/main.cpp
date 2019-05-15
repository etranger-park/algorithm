#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <map>

using namespace std;

int main()
{
  int T;
  scanf("%d", &T);
  for(int test = 1; test <= T; test++)
  {
    int N,K, value, num = 0;
    scanf("%d %d", &N, &K);
    int C[110000] ={ 0,};
    int MAX_C[110000] ={ 0,};
    int D[110000] ={ 0,};
    int MAX_D[110000] ={ 0,};
    int max_c = 0, max_d = 0;
    for(int i = 0; i < N; i++)
    {
      scanf("%d", &C[i]);
      if(max_c < C[i])
      {
        max_c = C[i];
      }
      MAX_C[i] = max_c;
    }
    for(int i = 0; i < N; i++)
    {
      scanf("%d", &D[i]);
      if(max_d < D[i])
      {
        max_d = D[i];
      }
      MAX_D[i] = max_d;
    }
    for(int j = N)

    printf("Case #%d: %d\n",test, num);
  }
}