#include <stdio.h>
#include <algorithm>

#define p1 2 // 1 to 100
#define p2 3 // 101 to 10000
#define p3 5 //10001 to 1000000
#define p4 7 // > 1000000
#define u1 100
#define u2 9900
#define u3 990000

long long int prices[] = {p1, p2, p3, p4};
long long int usages[] = {u1, u2, u3};
long long int a, b; // scan value
long long int use_total;

long long int price_to_use(long long int _price)
{
  long long int price = _price;
  long long int use = 0;
  for (int i = 0; i < 4; i++)
  {
    if (i == 3)
    {
      use += price / prices[i];
    }
    else
    {
      if (prices[i] * usages[i] < price)
      {
        // printf("remain %u, minus %u use %u\n",price,prices[i] * usages[i],use);
        price -= prices[i] * usages[i];
        use += usages[i];
      }
      else
      {
        use += (price / prices[i]);
        price = 0;
      }
    }
    if (price == 0)
      break;
  }
  return use;
}

long long int use_to_cost(long long int _use)
{
  long long int use = _use;
  long long int cost = 0;
  for(int i = 0; i<3; i++)
  {
    if(use >= usages[i])
    {
      use -= usages[i];
      cost += prices[i] * usages[i];
    }
    else
    {
      cost += prices[i] * use;
      use = 0;
    }
    if(use == 0) break;
  }
  if(use>0) cost += prices[3] * use;
  return cost;
}

long long int cumulative_use(int section)
{
  long long int val = 0;
  for(int i =0; i < section; i++)
    val += usages[i];
  return val;
}

//wlog s1 > s2, 
long long int calc_cost_ru2(int s1, int s2)
{
  // calc c
  long long int c = 0;
  for (int i = s1 - 1; i >= s2; i--)
  {
    c += prices[i] * usages[i];
  }
  // calc c done
  long long int use_s1 = cumulative_use(s1);
  long long int use_s2 = cumulative_use(s2);
  long long int d = b - c + prices[s2] * (use_total -  use_s1 - use_s2);
  // printf("use_s1:%lld use_s2:%lld, use_total:%lld D:%lld\n",use_s1, use_s2,use_total, d);
  if(d<0) return -1;
  long long int p = prices[s1] + prices[s2];
  if((d % p) == 0) 
  {
    if((s1 == 3) ||  (d / p) <= usages[s1])
    {
      long long int use_ru2 = use_total - use_s1 - d/(prices[s1] + prices[s2]);
      // printf("use_ru2: %lld\n",use_ru2);
      if(s2 == 3) 
        return use_to_cost(use_ru2);
      else if(use_ru2 < cumulative_use(s2+1))
        return use_to_cost(use_ru2);
      return -1;
    }
    return -1;
    
  }
  return -1;
}

int main()
{
  // printf("%lld\n", use_to_cost(2000003));
  while (true)
  {
    scanf("%lld %lld", &a, &b);
    if (a == 0 && b == 0)
      break;
    use_total = price_to_use(a); // 사용량1(ru1) + 사용량2(ru2), ru1 > ru2
    // printf("사용량 합: %lld\n", use_total);
    bool is_break = false;
    for(int s2 = 0; s2<4; s2++)
    {
      for(int s1 = s2; s1 < 4; s1++)
      {
        // printf("Start, s1:%d s2:%d\n",s1,s2);
        long long int cost_ru2 = calc_cost_ru2(s1,s2);
        // printf("s1:%d s2:%d cost_ru2:%lld\n",s1,s2, cost_ru2);
        if(cost_ru2 == -1) continue;
        printf("%lld\n",cost_ru2);
        is_break = true;
        break;
      }
      if (is_break) break;
    }
  }
  return 0;
}