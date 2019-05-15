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
    int P,Q;
    int n_values[110000] = { 0, };
    int s_values[110000] = { 0, };
    int w_values[110000] = { 0, };
    int e_values[110000] = { 0, };
    scanf("%d %d", &P, &Q);
    for(int p = 0; p < P ; p++)
    {
      int x,y;
      string d;
      cin >> x >> y >> d;
      if(d=="W")
      {
        w_values[x-1] ++;
      }
      else if(d=="E")
      {
        e_values[x+1] ++;
      }
      else if(d=="N")
      {
        n_values[y+1] ++;
      }
      else if(d=="S")
      {
        s_values[y-1]++;
      }
    }
    int ns_values[110000] = { 0, };
    int ew_values[110000] = { 0, };
    int value_ns = 0, value_ew = 0;
    for(int i = 0; i <= Q; i ++)
    {
      value_ns += n_values[i];
      value_ew += e_values[i];
      ns_values[i] += value_ns;
      ew_values[i] += value_ew;
    }
    value_ns = 0;
    value_ew = 0;
    int max_ns = 0, max_ew = 0;
    int max_y = 0, max_x = 0;
    for(int i = Q; i >= 0; i --)
    {
      value_ns += s_values[i];
      value_ew += w_values[i];
      ns_values[i] += value_ns;
      ew_values[i] += value_ew;
      if(ns_values[i] >= max_ns)
      {
        max_ns = ns_values[i];
        max_y = i;
      }
      if(ew_values[i] >= max_ew)
      {
        max_ew = ew_values[i];
        max_x = i;
      }
    }
    printf("Case #%d: %d %d\n",test, max_x, max_y);
  }
}