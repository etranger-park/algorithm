#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>

using namespace std;

map<int,int> min_map; //(min -> locate)

int up(int a)
{
    int h,new_val;
    map<int,int>::iterator it_map;
    set<int>::iterator it_set;
    if(a<= min_map.begin()->first) it_map = min_map.begin();
    else
    {
        for(it_map = min_map.end();it_map != min_map.begin();)
        {
            it_map--;
            int d_r = it_map->first;
            if(d_r == a) break;
            else if(d_r > a) continue;
            else
            {
                it_map++;
                break;
            }
        }
    }
    h = it_map -> second;

    if(it_map != min_map.begin())
        min_map.erase(min_map.begin(),it_map);

    new_val = h;
    min_map[it_map -> first] = --new_val;

    if(++it_map == min_map.end()) return -1;

    if(it_map->first == new_val)
    {
     //아래부터 쌓아 올려서 해당 폭을 가지는 애가 가득 찼을 때
        min_map.erase(--it_map);
    }
    return h;
}

int main()
{
    int radius,d, n,i,max_h,min_val = 2000000000;
    scanf("%d %d",&d,&n);
    int *d_min = (int *) malloc(sizeof(int)*d);
    map<int,int>::iterator it_map;

    for(i=0;i<d;i++)
    {
        scanf("%d",&radius);
        if(min_val > radius)
        {
            min_map.insert(pair<int,int>(min_val,i-1));
            min_val = radius;

        }
        *(d_min + i) = min_val;
    }

    min_map.insert(pair<int,int>(min_val,i-1)); // insert the last min value
    /*
    for(it_map =min_map.begin();it_map!=min_map.end();it_map++)
    {
        printf("min: %d -> locate: %d\n",it_map->first,it_map->second);
    }*/

    for(i=0;i<n;i++)
    {
        scanf("%d",&radius);
        max_h = up(radius);
        if(max_h == -1)
        {
            printf("0");
            return 0;
        }
        //printf("%d: r=%d h=%d\n",i,n_val,max_h);
    }
    printf("%d",max_h+1);

    return 0;
}
