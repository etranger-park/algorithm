#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

#define MAX_NODE 100001

using namespace std;

typedef pair<int, int> pii;

bool visit[MAX_NODE];
vector<pii> vc[MAX_NODE];

void prim(int start)
{
    visit[start] = true;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // 1번 정점을 시작점으로 한다.
    for (int i = 0; i < vc[start].size(); i++)
    {
        // 정점과 가중치를 priority_queue에 넣어준다.
        int next = vc[start][i].first;
        int nextCost = vc[start][i].second;

        pq.push(pii(nextCost, next));
    }

    uint64_t ans = 0;
    uint64_t max_val = 0;
    while (!pq.empty())
    {
        int here = pq.top().second;
        int hereCost = pq.top().first;

        pq.pop();

        // 이미 방문한 정점은 무시한다.
        if (visit[here])
            continue;

        visit[here] = true;
        if(max_val < hereCost) max_val = (uint64_t) hereCost;
        ans += (uint64_t)hereCost;

        // 다음 정점을 우선순위 큐에 넣어준다.
        for (int i = 0; i < vc[here].size(); i++)
        {
            int there = vc[here][i].first;
            int thereCost = vc[here][i].second;

            pq.push(pii(thereCost, there));
        }
    }
    ans -= max_val;
    cout << ans << endl;


}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    for (int i = 0; i < E; i++)
    {
        int from, to, val;
        scanf("%d %d %d", &from, &to, &val);

        vc[from].push_back(pii(to, val));
        vc[to].push_back(pii(from, val));
    }

    prim(1);

    return 0;
}
