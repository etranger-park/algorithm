#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

int main()
{
    int n,i,lines=0,before;
    map<int,int> val_x;
    map<int,int> val_y;
    map<int, int>::iterator it;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        it = val_x.find(x);
        if(it != val_x.end())
        {
            before = it->second;
            if(before == 1)
                lines += before;
            val_x[x] = before + 1;
        }
        else
            val_x.insert(pair<int,int>(x,1));

        it = val_y.find(y);
        if(it != val_y.end())
        {
            before = it->second;
            if(before == 1)
                lines += before;
            val_y[y] = before + 1;
        }
        else
            val_y.insert(pair<int,int>(y,1));
    }
    printf("%d",lines);
    return 0;
}
