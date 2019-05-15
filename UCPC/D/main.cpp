#include <iostream>
#include <vector>

#define MAX_N 500001
using namespace std;

vector<int> data[MAX_N];
int child_num[MAX_N];

int N;
uint64_t makeTree(int parent, int src)
{
    vector<int>::iterator it;
    uint64_t result = 0;
    int child =  0;
    for(it=data[src].begin();it!=data[src].end();it++)
    {
        if(*it == parent) continue;
        uint64_t value = makeTree(src,(*it));
        child += child_num[(*it)];
        result = result + value  + (uint64_t)child_num[(*it)];
    }
    if(child == 0)
    {
        child_num[src] = 1;
        return (uint64_t) 0;
    }
    child_num[src] = child;
    return result;
}

int main()
{
    int i;
    uint64_t result;
    cin >> N;
    for(i=0;i<N-1;i++)
    {
        int a,b;
        cin >> a >>b;
        data[a].push_back(b);
        data[b].push_back(a);
    }
    result = makeTree(0,1);
    if(result % 2 == 1)
        cout <<"Yes" <<endl;
    else
        cout <<"No" <<endl;

    return 0;
}
