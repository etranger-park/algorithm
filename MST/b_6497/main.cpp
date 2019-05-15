#include <iostream>
#include <cstdio>
#include <memory.h>
#include <vector>
#include <queue>
#include <functional>

#define MAX_NODE 200001

using namespace std;

typedef pair<uint32_t, uint32_t> puu;

bool visit[MAX_NODE];
vector<puu> vc[MAX_NODE];

uint32_t all_cost = 0;
void prim(int start)
{
    visit[start] = true;

    priority_queue<puu, vector<puu>, greater<puu>> pq;

    // 1번 정점을 시작점으로 한다.
    for (uint32_t i = 0; i < vc[start].size(); i++)
    {
        // 정점과 가중치를 priority_queue에 넣어준다.
        uint32_t next = vc[start][i].first;
        uint32_t nextCost = vc[start][i].second;

        pq.push(puu(nextCost, next));
    }

    uint32_t ans = 0;
    while (!pq.empty())
    {
        uint32_t here = pq.top().second;
        uint32_t hereCost = pq.top().first;

        pq.pop();

        // 이미 방문한 정점은 무시한다.
        if (visit[here])
            continue;

        visit[here] = true;
        ans += hereCost;

        // 다음 정점을 우선순위 큐에 넣어준다.
        for (uint32_t i = 0; i < vc[here].size(); i++)
        {
            uint32_t there = vc[here][i].first;
            uint32_t thereCost = vc[here][i].second;

            pq.push(puu(thereCost, there));
        }
    }
    ans = all_cost - ans;
    cout << ans << endl;
    return;
}

int main()
{
    int V, E;
    while(true)
    {
        scanf("%d %d", &V, &E);
        if(V==0,E==0) break;
        all_cost = 0;
        for (int i = 0; i < E; i++)
        {
            uint32_t from, to,val;
            scanf("%u %u %u", &from, &to, &val);
            all_cost += val;
            vc[from].push_back(puu(to, val));
            vc[to].push_back(puu(from, val));
        }
        prim(1);
        memset(visit,0,sizeof(visit));
        memset(vc,0,sizeof(vc));
    }
    return 0;
}

/*
성진이는 한 도시의 시장인데 거지라서 전력난에 끙끙댄다. 그래서 원래 모든 길마다 켜져 있던 가로등 중 일부를 소등하기로 하였다. 길의 가로등을 켜 두면 하루에 길의 미터 수만큼 돈이 들어가는데, 일부를 소등하여 그만큼의 돈을 절약할 수 있다.
그러나 만약 어떤 두 집을 왕래할 때, 불이 켜져 있지 않은 길을 반드시 지나야 한다면 위험하다. 그래서 도시에 있는 모든 두 집 쌍에 대해, 불이 켜진 길만으로 서로를 왕래할 수 있어야 한다.
위 조건을 지키면서 절약할 수 있는 최대 액수를 구하시오.
*/
