#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
#define MAX_M 1001
struct DisjointSet {
    vector<int> parent,level;
    DisjointSet(int n) : parent(n+1),level(n+1,1){
        for(int i=1; i <= n; ++i)
            parent[i] = i;
    }
    int find_root(int u) {
        if(u==parent[u]) return u;
        return parent[u] = find_root(parent[u]);
    }
    void merge(int u, int v){
        u = find_root(u); v= find_root(v);
        if(u==v) return;
        if(level[u] > level[v]) swap(u,v);
        parent[u] = v;
        if(level[u]==level[v]) ++level[v];
    }
};


int main()
{
    int N,M,i,j;
    int path[MAX_M];
    scanf("%d",&N);
    scanf("%d",&M);

    DisjointSet djs = DisjointSet(N);
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            int ca;
            scanf("%d",&ca);
            if(ca == 1)
                djs.merge(i,j);
        }
    }
    for(i=0;i<M;i++)
    {
        scanf("%d",path+i);
    }
    for(i=0;i<M-1;i++)
    {
        int u,v;
        u = djs.find_root(path[i]); v = djs.find_root(path[i+1]);
        if(u==v) continue;
        else
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
