#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>

#define MAX_V 20001
#define INF 100000000

using namespace std;

int V;

vector<int> dijkstra(int src,vector<pair<int, int>> *adj )
{
    vector<int> dist(V+1, INF);
    dist[src] = 0;
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
      int cost = pq.top().first;
      int here = pq.top().second;
      pq.pop();

      if (dist[here] < cost) continue;

      for (int i = 0; i < adj[here].size(); ++i) {
        int there = adj[here][i].first;
        int nextDist = cost + adj[here][i].second;
        if (dist[there] > nextDist) {
          dist[there] = nextDist;
          pq.push(make_pair(nextDist, there));
        }
      }
    }
    return dist;
}

int main()
{
    int E,SRC;
    int i,max_cost = 0;
    vector<pair<int, int>> adj[MAX_V];
    vector<pair<int, int> > adj_reverse[MAX_V];
    vector<int> result,result_reverse;
    scanf("%d %d %d",&V,&E,&SRC);

    for(i=0;i<E;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        adj[u].push_back(make_pair(v,w));
        adj_reverse[v].push_back(make_pair(u,w));
    }

    result = dijkstra(SRC,adj);
    result_reverse = dijkstra(SRC,adj_reverse);
    for(i=1;i<=V;i++)
    {
        int sum = result[i]+result_reverse[i];
        if(max_cost < sum)
            max_cost = sum;
    }
    printf("%d",max_cost);
    return 0;
}
/* Problem 1238
첫째 줄에 N(1 <= N <= 1,000), M(1 <= M <= 10,000), X가 공백으로 구분되어 입력된다. 두 번째 줄부터 M+1번째 줄까지 i번째 도로의 시작점, 끝점, 그리고 이 도로를 지나는데 필요한 소요시간 Ti가 들어온다.
모든 학생들은 집에서 X에 갈수 있고, X에서 집으로 돌아올 수 있는 데이터만 입력으로 주어진다
첫 번째 줄에 N명의 학생들 중 오고 가는데 가장 오래 걸리는 학생의 소요시간을 출력한다.
 */
