#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//오름차순 정렬
struct cmp
{
    bool operator()(pair<uint32_t, uint32_t> r,pair<uint32_t,uint32_t>l)
    {
        if( r.second == l.second)
            return r.first > l.first;
        return r.second > l.second;
    }
};

priority_queue<pair<uint32_t,uint32_t>,vector<pair<uint32_t,uint32_t>>,cmp> pq;
int N;


int main()
{
    int i;
    int c = 0;
    uint32_t start = 0;
    cin >> N;
    for(i=0;i<N;i++)
    {
        uint32_t start,finish;
        cin >> start >> finish;
        pq.push(make_pair(start,finish));
    }
    while(!pq.empty())
    {
        pair<uint32_t,uint32_t> value = pq.top();
        pq.pop();
        if(start <= value.first)
        {
            start = value.second;
            c++;
        }
    }
    cout << c << endl;
    return 0;
}
