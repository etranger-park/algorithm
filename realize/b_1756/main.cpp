#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
  int D,N;
  cin >> D >> N;
  int oven[D+100];
  map<int, pair<int, int> > change_point; // min_dia, (height, depth)
  map<int, pair<int, int> >::iterator change_it;

  int min_dia;
  cin >> min_dia;
  int depth = 1;
  int start = 1;
  for(int i = 2; i <= D; i++)
  {
    int dia;
    cin >> dia;
    if(min_dia > dia)
    {
      change_point.insert(make_pair(min_dia, make_pair(start, depth)));
      depth = 0;
      start = i;
      min_dia = dia;
    }
    depth ++;
    oven[i] = min_dia;
  }
  change_point.insert(make_pair(min_dia, make_pair(start, depth))); // 마지막 처리

  // for(change_it = change_point.begin(); change_it != change_point.end();change_it ++)
  // {
  //   cout << "point dia:" << change_it->first <<" when height:"<< change_it->second.first << "depth: "<<change_it->second.second<<endl;
  // }
  int result;
  for(int i = 0; i < N; i++)
  {
    int dia;
    cin >> dia;
    change_it = change_point.upper_bound(dia - 1); // 같은 크기도 찾아야 함으로.
    if(change_it == change_point.end())
    {
      result = 0;
      break;
    }
    if(change_it != change_point.begin())
      change_point.erase(change_point.begin(), change_it);
    change_it->second.second --;
    result = change_it->second.first + change_it->second.second;
    // cout << result << endl;
    if(change_it->second.second == 0) change_point.erase(change_it);
  }
  cout << result << endl;
  return 0;
}