#include <iostream>
#include <cstdio>
#include <vector>

#define MAX_N 1000001
using namespace std;

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
    int N,M,i;
    scanf("%d %d",&N,&M);
    DisjointSet djs = DisjointSet(N);
    for(i=0;i<M;i++)
    {
        int ca,a,b;
        scanf("%d %d %d",&ca,&a,&b);
        if(ca == 0)
            djs.merge(a,b);
        else if(ca == 1)
        {
            int u = djs.find_root(a); int v = djs.find_root(b);
            if(u==v) printf("YES\n");
            else printf("NO\n");
        }

    }
    return 0;
}
