#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Node
{
  int R;
  int C;
  vector<Node> neigh;
};

vector<Node> MakeGraph(int R, int C)
{
  vector<Node> graph(R*C);
  for(int i = 0; i < R; i ++)
  {
    for(int j = 0; j < C; j++)
    {
      
    }
  }
  return graph;
}

bool CheckPossible(int R, int C)
{
  return true;
}

int main()
{
  int test_case;
  scanf("%d", &test_case);
  for(int test_index = 1; test_index <= test_case; test_index++)
  {
    int R, C;
    scanf("%d %d", &R, &C);
    bool result = CheckPossible(R,C);
    std::string MESSAGE = result ? "POSSIBLE" : "IMPOSSIBLE";
    cout << "Case #" << test_index <<": "<<MESSAGE<<endl;
  }
  return 0;
}