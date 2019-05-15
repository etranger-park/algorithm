#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>

#define MAX_R 2001
#define MAX_C 201
#define MAX_D 200001
#define INF 2100000000

using namespace std;

vector<pair<uint32_t,uint32_t> > adj[2*MAX_R];

uint16_t arr_cost[MAX_R][MAX_C] = {0};
uint32_t right_to_node[MAX_R][MAX_C] = {0};
uint32_t left_to_node[MAX_R][MAX_C] = {0};

pair<uint16_t,uint16_t> arr_dest[MAX_D];

vector<uint32_t> dijk_result[2*MAX_R];

int R,C,D;

vector<uint32_t> dijkstra(uint16_t src)
{
    if(!dijk_result[src].empty()) return dijk_result[src];
    vector<uint32_t> dist(2*R+1, INF);
    dist[src] = 0;
    priority_queue<pair<uint32_t, uint32_t>,vector<pair<uint32_t,uint32_t>>,greater<pair<uint32_t,uint32_t>>> pq;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
      uint32_t cost = pq.top().first;
      uint32_t here = pq.top().second;
      pq.pop();

      if (dist[here] < cost) continue;

      for (int i = 0; i < adj[here].size(); ++i) {
        uint32_t there = adj[here][i].first;
        uint32_t nextDist = cost + adj[here][i].second;

        if (dist[there] > nextDist) {
          dist[there] = nextDist;
          pq.push(make_pair(nextDist, there));
        }
      }
    }
    dijk_result[src] = dist;
    return dist;
}

int main()
{
    int i,j;
    uint64_t result = 0;

    scanf("%d %d",&R,&C);
    for(i=1;i<=R;i++)
    {
        uint32_t sum = 0;
        for(j=1;j<=C;j++)
        {
            scanf("%hu",&arr_cost[i][j]);
            if(j!=1 && j!=C)
            {
                sum+= (int) arr_cost[i][j];
                left_to_node[i][j] = sum;
            }
            else if(j==1)
                left_to_node[i][1] = 0;
            else
                left_to_node[i][C] = sum + (uint32_t) arr_cost[i][j] ;
        }
        adj[2*i -1].push_back(make_pair(2*i,sum +arr_cost[i][C]));
        adj[2*i].push_back(make_pair(2*i - 1,sum +arr_cost[i][1]));
        if(i == 1) continue;
        adj[2*i -1].push_back(make_pair(2*(i-1) -1,arr_cost[i-1][1]));
        adj[2*i].push_back(make_pair(2*(i-1),arr_cost[i-1][C]));
        adj[2*(i-1) -1].push_back(make_pair(2*i-1,arr_cost[i][1]));
        adj[2*(i-1)].push_back(make_pair(2*i,arr_cost[i][C]));

        sum = 0;
        for(j=C;j>=1;j--)
        {
            if(j!=C) sum +=(uint32_t) arr_cost[i][j];
            right_to_node[i][j] =sum;
        }
    }
    result = (uint64_t) arr_cost[1][1];

    scanf("%d",&D);
    arr_dest[0] = pair<uint16_t,uint16_t>(1,1);

    for(i=1;i<=D;i++)
    {
        uint16_t dest_r,dest_c,src_r,src_c;
        vector<uint32_t> src_right,src_left;
        vector<uint32_t>::iterator it;
        scanf("%hu %hu",&dest_r,&dest_c);
        arr_dest[i]=pair<uint16_t,uint16_t>(dest_r,dest_c);
        src_r = arr_dest[i-1].first;
        src_c = arr_dest[i-1].second;

        uint32_t go_right, go_left,from_right,from_left,final_val;
        go_right = right_to_node[src_r][src_c] - arr_cost[src_r][src_c] + arr_cost[src_r][C];
        go_left = left_to_node[src_r][src_c] - arr_cost[src_r][src_c] + arr_cost[src_r][1];
        src_left =dijkstra(src_r*2-1);
        src_right =dijkstra(src_r*2);
        from_right = right_to_node[dest_r][dest_c];
        from_left = left_to_node[dest_r][dest_c];

        if(dest_r == src_r) //src and dest has same row
        {
            uint32_t direct = 0;
            if(src_c <dest_c) //SRC < DEST
            {
                for(j=src_c+1 ; j<=dest_c;j++)
                    direct += (uint32_t) arr_cost[dest_r][j];
                final_val = min(go_left+src_left[dest_r*2]+from_right,direct);
            }
            else //DEST <SRC
            {
                for(j=src_c-1 ; j>=dest_c;j--)
                    direct += (uint32_t) arr_cost[dest_r][j];
                final_val = min(direct,go_right+src_right[dest_r*2-1]+from_left);
            }
        }
        else
        {
            uint32_t l2l,l2r,r2l,r2r;
            //case1 src_left to dest_left
            l2l = go_left + src_left[dest_r*2 -1] + from_left;
            //case2 src_left to dest_right
            l2r = go_left + src_left[dest_r*2] + from_right;
            //case3 src_right to dest_left
            r2l = go_right +src_right[dest_r*2-1] +from_left;
            //case4 src_right to dest_right
            r2r = go_right + src_right[dest_r*2] +from_right;
            final_val = min(min(l2l,l2r),min(r2l,r2r));
        }
        result += (uint32_t) final_val;
    }
    cout << result << endl;
    return 0;
}
/* 2939 택배배달
첫째 줄에 도시의 크기 R과 C가 주어진다. (1 ≤ R ≤ 2000, 1 ≤ C ≤ 200)
다음 R개 줄에는, 각 칸을 통과하는데 드는 시간이 주어진다. 이 시간은 0보다 크거나 같고, 5000보다 작거나 같은 자연수이다.
다음 줄에는 배달해야 하는 물품의 수 D (1 ≤ D ≤ 200000)가 주어진다. 다음 D개 줄에는 물품을 배달해야 하는 곳의 위치의 좌표가 배달해야 하는 순서대로 주어진다.
같은 곳이 여러 번 주어질 수는 있다. 하지만, 연속해서 같은 곳을 배달해야 하는 경우는 없다.
*/
