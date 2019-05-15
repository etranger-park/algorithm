// 백준 1396번 크루스칼의 공
// UnionFind 와 parallel binary search 사용
#include <stdio.h>
#include <vector>       // std::vector
#include <utility>      // std::pair, std::make_pair
#include <algorithm>    // std::sort
#include <string.h>     // std::memset

using namespace std;

#define MAX_NUM 100010
int height[MAX_NUM];
int parent[MAX_NUM];
int set_size[MAX_NUM];

int find(int idx)
{
  if(idx == parent[idx])
    return idx;
  return parent[idx] = find(parent[idx]);
}

void merge(int left, int right)
{
  int left_parent = find(left);
  int right_parent = find(right);
  if (left_parent == right_parent) return;
  if(height[left_parent] < height[right_parent]) 
  {
    swap(left, right);
    swap(left_parent, right_parent);
  }
  // left로 root 설정하기
  parent[right_parent] = left_parent;
  set_size[left_parent] += set_size[right_parent];
  if(height[left_parent] == height[right_parent])
    height[left_parent] ++;
}

void init(int n)
{
  for(int i = 1; i <= n; i++)
  {
    height[i] = 1;
    set_size[i] = 1;
    parent[i] = i;
  }
}

int main()
{
  int n, m;
  vector<pair<int,pair<int, int> > > edges; // vector of <cost, <start, end>>
  
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++)
  {
    int left, right, cost;
    scanf("%d %d %d",&left, &right, &cost);
    edges.push_back(make_pair(cost,make_pair(left,right)));
  }
  sort(edges.begin(),edges.end());

  int num_query;
  vector<pair<int, int> > queries;
  vector<int> low, high;

  scanf("%d", &num_query);
  for(int i = 0; i < num_query; i++)
  {
    int start, end;
    scanf("%d %d", &start, &end);
    queries.push_back(make_pair(start, end));
    low.push_back(0);
    high.push_back(m);
  }

  bool is_end = false;
  int num_passes[MAX_NUM];
  int min_temps[MAX_NUM];

  while(!is_end)
  {
    is_end = true;
    init(n);
    vector<vector<int> > vt;
    vt.resize(m+2);
    for (int i = num_query - 1; i > -1; i--) {
      // printf("index:%d low:%d, high:%d\n", i, low[i], high[i]);
      if (low[i] < high[i]) 
        vt[(low[i] + high[i]) >> 1].push_back(i);
    }
    for(int i = 0; i < m; i++)
    {
      merge(edges[i].second.first, edges[i].second.second);
      while(!vt[i].empty())
      {
        is_end = false;
        int query_index = vt[i].back();
        vt[i].pop_back();
        // printf("%d 번째 쿼리, %d 간선에 대해서\n", query_index, i);
        pair<int, int> query = queries[query_index];
        int parent_start = find(query.first);
        int parent_end = find(query.second);
        // printf("start parent %d, end parent %d\n",parent_start, parent_end);
        if(parent_start == parent_end)
        {
          high[query_index] = i;
          num_passes[query_index] = set_size[parent_start];
          min_temps[query_index] = edges[i].first;
        }
        else
        {
          low[query_index] = i + 1;
        }
      }
    }
  }

  for(int i = 0; i < num_query; i++)
  {
    if(low[i] == m) printf("%d\n",-1);
    else
    {
      printf("%d %d\n", min_temps[i], num_passes[i]);
    }
  }
  return 0;
}