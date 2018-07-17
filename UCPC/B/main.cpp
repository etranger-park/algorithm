#include <iostream>
#include<queue>
#include<vector>

using namespace std;

int N,M;
priority_queue<uint64_t,vector<uint64_t>,greater<uint64_t>> pq;
uint64_t sum = 0;

void doing()
{
    uint64_t first = pq.top();
    pq.pop();
    uint64_t second = pq.top();
    pq.pop();
    sum = sum + first + second;
    pq.push(first + second);
    pq.push(first + second);
}

int main()
{
    int i;
    cin >> N >> M;
    for(i=0;i<N;i++)
    {
        uint64_t input;
        cin >> input;
        sum += input;
        pq.push(input);
    }
    for(i=0;i<M;i++)
    {
        doing();
    }
    cout << sum <<endl;
    return 0;
}
