#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_NODE 100001

using namespace std;

typedef pair<int, int> pii;
typedef pair<uint32_t,uint32_t> puu;
//vector 오름차순 정렬
bool comp_vc(pii p1, pii p2)
{
    return p1.second < p2.second;
}

//오름차순 정렬
struct comp_pq
{
    bool operator()(puu r,puu l)
    {
        if( r.second == l.second)
            return r.first > l.first;
        return r.second > l.second;
    }
};

bool visit[MAX_NODE];
vector<puu> vc[MAX_NODE];
vector<pii> vc_x;//(Node, coordinate)
vector<pii> vc_y;
vector<pii> vc_z;

void prim(int start)
{
    visit[start] = true;

    priority_queue<puu, vector<puu>, comp_pq> pq;

    for (uint32_t i = 0; i < vc[start].size(); i++)
    {
        uint32_t next = vc[start][i].first;
        uint32_t nextCost = vc[start][i].second;

        pq.push(puu(next, nextCost));
    }

    uint64_t ans = 0;

    while (!pq.empty())
    {
        uint32_t here = pq.top().first;
        uint32_t hereCost = pq.top().second;

        pq.pop();

        if (visit[here])
            continue;

        visit[here] = true;

        ans += (uint64_t)hereCost;

        for (uint32_t i = 0; i < vc[here].size(); i++)
        {
            uint32_t there = vc[here][i].first;
            uint32_t thereCost = vc[here][i].second;

            pq.push(puu(there, thereCost));
        }
    }

    cout << ans << endl;
}
void make_edge()
{
    sort(vc_x.begin(),vc_x.end(),comp_vc);
    sort(vc_y.begin(),vc_y.end(),comp_vc);
    sort(vc_z.begin(),vc_z.end(),comp_vc);
    vector<pii>::iterator it1,it2;
    for(it1=vc_x.begin(),it2=vc_x.begin()+1; it2!=vc_x.end();it1++,it2++)
    {
        uint32_t cost = (uint32_t)(it2->second - it1->second);
        vc[(uint32_t)(it1->first)].push_back(puu((uint32_t)(it2->first),cost));
        vc[(uint32_t)(it2->first)].push_back(puu((uint32_t)(it1->first),cost));
    }
    for(it1=vc_y.begin(),it2=vc_y.begin()+1; it2!=vc_y.end();it1++,it2++)
    {
        uint32_t cost = (uint32_t)(it2->second - it1->second);
        vc[(uint32_t)(it1->first)].push_back(puu((uint32_t)(it2->first),cost));
        vc[(uint32_t)(it2->first)].push_back(puu((uint32_t)(it1->first),cost));
    }
    for(it1=vc_z.begin(),it2=vc_z.begin()+1; it2!=vc_z.end();it1++,it2++)
    {
        uint32_t cost = (uint32_t)(it2->second - it1->second);
        vc[(uint32_t)(it1->first)].push_back(puu((uint32_t)(it2->first),cost));
        vc[(uint32_t)(it2->first)].push_back(puu((uint32_t)(it1->first),cost));
    }
    return;
}

int main()
{
    int V;
    scanf("%d", &V);

    for (int i = 0; i < V; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        vc_x.push_back(pii(i, x));
        vc_y.push_back(pii(i, y));
        vc_z.push_back(pii(i, z));
    }
    make_edge();
    prim(0);

    return 0;
}
