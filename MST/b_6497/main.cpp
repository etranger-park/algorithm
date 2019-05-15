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

    // 1�� ������ ���������� �Ѵ�.
    for (uint32_t i = 0; i < vc[start].size(); i++)
    {
        // ������ ����ġ�� priority_queue�� �־��ش�.
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

        // �̹� �湮�� ������ �����Ѵ�.
        if (visit[here])
            continue;

        visit[here] = true;
        ans += hereCost;

        // ���� ������ �켱���� ť�� �־��ش�.
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
�����̴� �� ������ �����ε� ������ ���³��� �������. �׷��� ���� ��� �渶�� ���� �ִ� ���ε� �� �Ϻθ� �ҵ��ϱ�� �Ͽ���. ���� ���ε��� �� �θ� �Ϸ翡 ���� ���� ����ŭ ���� ���µ�, �Ϻθ� �ҵ��Ͽ� �׸�ŭ�� ���� ������ �� �ִ�.
�׷��� ���� � �� ���� �շ��� ��, ���� ���� ���� ���� ���� �ݵ�� ������ �Ѵٸ� �����ϴ�. �׷��� ���ÿ� �ִ� ��� �� �� �ֿ� ����, ���� ���� �游���� ���θ� �շ��� �� �־�� �Ѵ�.
�� ������ ��Ű�鼭 ������ �� �ִ� �ִ� �׼��� ���Ͻÿ�.
*/
