#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int test_case;
  scanf("%d", &test_case);
  for(int test_index = 1; test_index <= test_case; test_index++)
  {
    int N;
    string lydia_path, my_path;
    scanf("%d", &N);
    cin >> lydia_path;
    const int length = lydia_path.length();
    for(int i = 0; i < length; i++)
    {
      if(lydia_path[i] == 'S') my_path.append("E");
      if(lydia_path[i] == 'E') my_path.append("S");
    }
    cout << "Case #" << test_index <<": "<<my_path<<endl;
  }
  return 0;
}