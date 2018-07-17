#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#define MAX 100001

using namespace std;

bool check[MAX+100];

int bfs(int src,int dest)
{
    if(src == dest) return 0;
    int result=0;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        queue<int> tmp_q;
        while(!q.empty())
        {
            int val = q.front();
            q.pop();
            if(val == dest) return result;
            if(check[val]) continue;
            check[val] =true;
            if((val-1)>-1  ) tmp_q.push(val-1);
            if(2*val < (dest + 2)) tmp_q.push(2*val);
            if(val <dest) tmp_q.push(val+1);
        }
        q = tmp_q;
        result++;
    }
}

int main()
{
    int N,K,result;
    cin >> N >> K;
    result = bfs(N,K);
    cout << result << endl;
    return 0;
}
