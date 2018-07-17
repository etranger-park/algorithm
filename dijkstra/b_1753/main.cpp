#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>

#define MAX_V 20001
#define INF 100000000

using namespace std;

vector<pair<int, int> > adj[MAX_V];
int V;
vector<int> dijkstra(int src)
{
    vector<int> dist(V+1, INF);
    dist[src] = 0;
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
      int cost = pq.top().first;
      int here = pq.top().second;
      pq.pop();

      // ���� ���� ���� �ͺ��� �� ª�� ��θ� �˰� �ִٸ� ���� ���� ���� �����Ѵ�.
      if (dist[here] < cost) continue;

      // ������ �������� ��� �˻��Ѵ�.
      for (int i = 0; i < adj[here].size(); ++i) {
        int there = adj[here][i].first;
        int nextDist = cost + adj[here][i].second;
        // �� ª�� ��θ� �߰��ϸ�, dist[]�� �����ϰ� �켱���� ť�� �ִ´�.
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
    int i;
    vector<int> result;
    scanf("%d %d",&V,&E);
    scanf("%d",&SRC);
    for(i=0;i<E;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        adj[u].push_back(make_pair(v,w));
    }
    result = dijkstra(SRC);
    for(i=1;i<=V;i++)
    {
        int cost = result[i];
        if(cost==INF)
            printf("INF\n");
        else
            printf("%d\n",cost);
    }
    return 0;
}
